#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

#include "stm32f4xx_hal.h"  // 자신의 MCU 시리즈에 맞게 수정

extern UART_HandleTypeDef huart2; // 사용하는 UART 핸들

// stdout (printf)
__attribute__((weak)) int _write(int file, char *ptr, int len) {
    HAL_UART_Transmit(&huart2, (uint8_t *) ptr, len, HAL_MAX_DELAY);
    return len;
}

// stdin (scanf)
__attribute__((weak)) int _read(int file, char *ptr, int len) {
    char ch;
    int i = 0;

    for (; i < len; i++) {
        HAL_UART_Receive(&huart2, (uint8_t * ) & ch, 1, HAL_MAX_DELAY);

        if (ch == '\r') {
            ch = '\n';
            HAL_UART_Transmit(&huart2, (uint8_t *) "\r\n", 2, HAL_MAX_DELAY);
            *ptr++ = ch;
            i++;
            break;
        }

        *ptr++ = ch;
        HAL_UART_Transmit(&huart2, (uint8_t * ) & ch, 1, HAL_MAX_DELAY); // 에코
    }

    return i;
}

// 동적 메모리 할당 지원 (malloc 등)
extern char _end; // end of BSS, 링크 스크립트에 의해 정의됨
static char *heap_end;

caddr_t _sbrk(int incr) {
    extern char _estack;  // stack top, 링크 스크립트에 정의됨
    char *prev_heap_end;

    if (heap_end == 0) {
        heap_end = &_end;
    }

    if (heap_end + incr > &_estack) {
        errno = ENOMEM;
        return (caddr_t) - 1;
    }

    prev_heap_end = heap_end;
    heap_end += incr;
    return (caddr_t) prev_heap_end;
}

// 필수 dummy 함수들 (표준 C 라이브러리 호환용)
int _close(int file) { return -1; }

int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) { return 1; }

int _lseek(int file, int ptr, int dir) { return 0; }

int _open(const char *name, int flags, int mode) { return -1; }

int _kill(int pid, int sig) {
    errno = EINVAL;
    return -1;
}

int _getpid(void) { return 1; }