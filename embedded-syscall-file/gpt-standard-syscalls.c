#include <sys/stat.h>
#include <sys/unistd.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>

#define USARTx USART1  // 사용 중인 USART 포트 지정

extern char _end;
extern char _estack;
static char *heap_end;

// printf
int _write(int file, char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        while (!(USARTx->SR & USART_SR_TXE)); // 전송 가능 대기
        USARTx->DR = ptr[i];
    }
    return len;
}

// scanf
int _read(int file, char *ptr, int len) {
    int i = 0;
    char ch;

    for (; i < len; i++) {
        while (!(USARTx->SR & USART_SR_RXNE)); // 수신 대기
        ch = USARTx->DR;

        if (ch == '\r') {
            ch = '\n';
            _write(0, "\r\n", 2);
            ptr[i++] = ch;
            break;
        }

        ptr[i] = ch;
        _write(0, &ch, 1);  // 에코 출력
    }

    return i;
}

// malloc/free 지원
caddr_t _sbrk(int incr) {
    if (heap_end == 0)
        heap_end = &_end;

    if (heap_end + incr > &_estack) {
        errno = ENOMEM;
        return (caddr_t)-1;
    }

    char *prev_heap_end = heap_end;
    heap_end += incr;
    return (caddr_t)prev_heap_end;
}

// 표준 함수 더미 구현
int _close(int file) { return -1; }
int _fstat(int file, struct stat *st) { st->st_mode = S_IFCHR; return 0; }
int _isatty(int file) { return 1; }
int _lseek(int file, int offset, int whence) { return 0; }
int _open(const char *name, int flags, int mode) { return -1; }
int _kill(int pid, int sig) { errno = EINVAL; return -1; }
int _getpid(void) { return 1; }