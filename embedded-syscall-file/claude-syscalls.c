/**
 * @file    syscalls.c
 * @brief   Newlib syscall 구현 (Standard Peripheral Library / STM32F103RBT6)
 *
 * printf, scanf, malloc 사용을 위한 최소 syscall 구현.
 * USART1을 통해 UART I/O를 수행한다.
 *
 * 링커 스크립트 요구 심볼:
 *   _end             : .bss 섹션 종료 주소 (힙 시작점)
 *   _estack          : RAM 끝 주소 (스택 최상단)
 *   _Min_Stack_Size  : 링커에서 예약한 최소 스택 크기
 *
 * 링커 플래그:
 *   -lc -lm -lnosys -specs=nano.specs -u _printf_float -u _scanf_float
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdint.h>

#include "stm32f10x.h"
#include "stm32f10x_usart.h"

/* --------------------------------------------------------------------------
 *  설정
 * -------------------------------------------------------------------------- */

/** printf/scanf에 사용할 USART 포트 */
#define SYSCALL_USART   USART1

/* --------------------------------------------------------------------------
 *  _write  —  printf / puts / fputs 지원
 * --------------------------------------------------------------------------
 *
 *  newlib가 stdout(fd=1), stderr(fd=2) 출력 시 호출한다.
 *  Standard Peripheral Library의 USART_SendData / USART_GetFlagStatus를 사용.
 *
 *  사용 예:
 *      printf("Hello %d\r\n", 42);
 *      printf("float = %.2f\r\n", 3.14f);   // -u _printf_float 필요
 */
int _write(int fd, char *ptr, int len)
{
    int i;
    for (i = 0; i < len; i++) {
        /* TXE(Transmit Data Register Empty) 플래그 대기 */
        while (USART_GetFlagStatus(SYSCALL_USART, USART_FLAG_TXE) == RESET);
        USART_SendData(SYSCALL_USART, (uint16_t)ptr[i]);
    }
    return len;
}

/* --------------------------------------------------------------------------
 *  _read  —  scanf / gets / fgets 지원
 * --------------------------------------------------------------------------
 *
 *  newlib가 stdin(fd=0) 입력 시 호출한다.
 *  '\r' (CR) 또는 '\n' (LF) 수신 시 입력을 종료한다.
 *
 *  에코(echo) 기능:
 *  - 기본적으로 에코는 비활성화 상태이다.
 *  - 터미널에서 타이핑 내용을 확인하려면 에코 주석을 해제한다.
 *  - 에코 활성화 시 Backspace/DEL 처리도 함께 동작한다.
 *
 *  사용 예:
 *      int val;
 *      scanf("%d", &val);
 *
 *  주의:
 *  - 블로킹 함수이다. 문자가 수신될 때까지 리턴하지 않는다.
 *  - 인터럽트 기반 수신이 필요하면 별도 구현해야 한다.
 */
int _read(int fd, char *ptr, int len)
{
    int i = 0;
    char ch;

    while (i < len) {
        /* RXNE(Read Data Register Not Empty) 플래그 대기 */
        while (USART_GetFlagStatus(SYSCALL_USART, USART_FLAG_RXNE) == RESET);
        ch = (char)(USART_ReceiveData(SYSCALL_USART) & 0xFF);

        if (ch == '\r' || ch == '\n') {
            /* Enter 입력: 입력 종료 */
            /* _write(fd, "\r\n", 2); */    /* 에코: 줄바꿈 출력 */
            break;
        }

        if (ch == '\b' || ch == 0x7F) {
            /* Backspace / DEL 처리 */
            if (i > 0) {
                i--;
                /* _write(fd, "\b \b", 3); */   /* 에코: 커서 뒤로 + 지우기 + 커서 뒤로 */
            }
            continue;
        }

        /* 일반 문자 저장 */
        ptr[i++] = ch;
        /* _write(fd, &ch, 1); */               /* 에코: 입력 문자 출력 */
    }

    return i;
}

/* --------------------------------------------------------------------------
 *  _sbrk  —  malloc / calloc / realloc 지원
 * --------------------------------------------------------------------------
 *
 *  newlib의 malloc이 힙 메모리를 확장할 때 호출한다.
 *  링커 스크립트의 _end(힙 시작)부터 위로 확장하되,
 *  _estack - _Min_Stack_Size (스택 보호 영역)을 넘지 않도록 한다.
 *
 *  메모리 레이아웃 (STM32F103RBT6, RAM 20KB):
 *
 *    0x20000000 ┌──────────────────┐
 *               │ .data            │  초기화된 전역 변수
 *               ├──────────────────┤
 *               │ .bss             │  미초기화 전역 변수
 *               ├──────────────────┤ ← _end (힙 시작)
 *               │                  │
 *               │  Heap ↓ (증가)    │  malloc이 사용
 *               │                  │
 *               │                  │
 *               │  Stack ↑ (감소)   │  함수 호출, 지역 변수
 *               │                  │
 *               ├──────────────────┤ ← _estack - _Min_Stack_Size (스택 보호 경계)
 *               │ Stack Reserved   │  _Min_Stack_Size (0x400 = 1KB)
 *    0x20005000 └──────────────────┘ ← _estack (RAM 끝)
 *
 *  사용 예:
 *      char *buf = (char *)malloc(128);
 *      if (buf == NULL) { // 메모리 부족 처리 }
 *      free(buf);
 */
void *_sbrk(ptrdiff_t incr)
{
    extern uint8_t _end;            /* 링커 스크립트: .bss 섹션 끝 */
    extern uint8_t _estack;         /* 링커 스크립트: RAM 끝 (스택 최상단) */
    extern uint32_t _Min_Stack_Size;/* 링커 스크립트: 최소 스택 예약 크기 */

    static uint8_t *heap_end = NULL;
    uint8_t *prev_heap_end;

    /* 스택 보호 경계: _estack에서 _Min_Stack_Size만큼 뺀 위치 */
    const uint32_t stack_limit = (uint32_t)&_estack - (uint32_t)&_Min_Stack_Size;
    const uint8_t *max_heap = (uint8_t *)stack_limit;

    /* 첫 호출 시 힙 시작점 초기화 */
    if (heap_end == NULL) {
        heap_end = &_end;
    }

    /* 힙이 스택 보호 영역을 침범하는지 검사 */
    if (heap_end + incr > max_heap) {
        errno = ENOMEM;
        return (void *)-1;
    }

    prev_heap_end = heap_end;
    heap_end += incr;

    return (void *)prev_heap_end;
}

/* --------------------------------------------------------------------------
 *  newlib 필수 스텁 함수
 * --------------------------------------------------------------------------
 *
 *  newlib가 내부적으로 호출하는 POSIX 함수들의 최소 구현.
 *  임베디드 환경에서는 파일 시스템이 없으므로 스텁으로 처리한다.
 *  -lnosys 링크 시 이 함수들이 자동 제공되지만,
 *  명시적으로 정의하면 링커 경고를 방지할 수 있다.
 */

/**
 * @brief   파일 디스크립터 닫기
 * @param   fd  닫을 파일 디스크립터 번호
 * @return  -1 (항상 실패 — 실제 파일 시스템 없음)
 *
 * newlib 내부에서 fclose() 등 호출 시 사용된다.
 * 임베디드 환경에서는 파일 개념이 없으므로 항상 -1을 반환한다.
 */
int _close(int fd)
{
    (void)fd;
    return -1;
}

/**
 * @brief   파일 디스크립터의 상태 정보 조회
 * @param   fd  파일 디스크립터 번호
 * @param   st  상태 정보를 저장할 구조체 포인터
 * @return  0 (성공)
 *
 * newlib 내부에서 printf/scanf 초기화 시 stdout/stdin의 타입을 확인하기 위해 호출한다.
 * S_IFCHR(문자 디바이스)로 보고하여 버퍼링 없는 문자 단위 I/O를 유도한다.
 */
int _fstat(int fd, struct stat *st)
{
    (void)fd;
    st->st_mode = S_IFCHR;
    return 0;
}

/**
 * @brief   파일 디스크립터가 터미널(TTY)인지 확인
 * @param   fd  파일 디스크립터 번호
 * @return  1 (항상 터미널)
 *
 * newlib가 stdout의 라인 버퍼링 여부를 결정할 때 호출한다.
 * 1을 반환하면 '\n' 출력 시 자동으로 버퍼를 플러시한다.
 */
int _isatty(int fd)
{
    (void)fd;
    return 1;
}

/**
 * @brief   파일 내 읽기/쓰기 위치 이동 (seek)
 * @param   fd      파일 디스크립터 번호
 * @param   offset  이동할 바이트 수
 * @param   whence  기준 위치 (SEEK_SET, SEEK_CUR, SEEK_END)
 * @return  0 (항상 시작 위치 — 시리얼은 seek 불가)
 *
 * UART는 스트림 디바이스이므로 seek 동작이 무의미하다.
 * 항상 0을 반환하여 현재 위치가 시작점임을 나타낸다.
 */
int _lseek(int fd, int offset, int whence)
{
    (void)fd;
    (void)offset;
    (void)whence;
    return 0;
}

/**
 * @brief   현재 프로세스 ID 반환
 * @return  1 (고정값)
 *
 * 임베디드 환경에서는 단일 프로세스만 실행되므로 항상 1을 반환한다.
 * newlib 내부의 signal 처리 등에서 참조된다.
 */
int _getpid(void)
{
    return 1;
}

/**
 * @brief   프로세스에 시그널 전송
 * @param   pid  대상 프로세스 ID
 * @param   sig  시그널 번호
 * @return  -1 (항상 실패 — 프로세스 관리 없음)
 *
 * 임베디드 환경에서는 프로세스 간 시그널 개념이 없다.
 * abort() 호출 시 내부적으로 _kill(getpid(), SIGABRT)이 호출된다.
 */
int _kill(int pid, int sig)
{
    (void)pid;
    (void)sig;
    errno = EINVAL;
    return -1;
}

/**
 * @brief   프로그램 종료
 * @param   status  종료 코드
 *
 * exit() 또는 abort() 호출 시 최종적으로 실행된다.
 * 임베디드 시스템은 OS에 제어권을 반환할 수 없으므로
 * 무한 루프로 진입하여 시스템을 정지시킨다.
 * 실제 운용 시에는 여기서 워치독 리셋 등을 수행할 수 있다.
 */
void _exit(int status)
{
    (void)status;
    while (1) {
        /* 무한 루프 - 임베디드 시스템은 종료하지 않음 */
    }
}
