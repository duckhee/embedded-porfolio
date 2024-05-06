#include "Hw_Config.h"
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>

#include "../CMSIS/Core/CM3/stm32f10x.h"

#define  U1_BUFFER_SIZE  100

register char *stack_ptr asm("sp");

char *__env[1] = {0};
char **environ = __env;

//retargetting _write
//해당 객체 또는 함수가 참조되지 않아도 사용하는 것처럼 컴파일러로 하여금 삭제되지 않도록 한다. __attribute__((used))
__attribute__ ((used)) int _write(int fd, char *ptr, int len) {
    /* Write "len" of char from "ptr" to file id "fd"
   * Return number of char written.
   * Need implementing with UART here. */
    size_t i;
    for (i = 0; i < len; i++) {
        USART_SendData(USART1, ptr[i]);
        while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    }
    return len;
}

__attribute__((used)) int _read(int fd, char *ptr, int len) {
    size_t i;
    for (i = 0; i < len; ++i) {
        while ((USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET));
        *ptr++ = USART_ReceiveData(USART1);
        if (*ptr == '\n') {
            break;
        }
    }
    return i;
}

/*
__attribute__ ((used)) int _read(int fd, char *ptr, int len)
{
   size_t i ;
   for(i = 0; i < len; ++i)
   {
       while((USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET));
       ptr[i] = USART_ReceiveData(USART1);
       if(ptr[i] == '\n')
       {
           break;
       }
       if(0 || (i>0))
       {
           return i;
       }
   }
    return i;
}
*/
/*
__attribute__ ((used)) int _read(int fd, char *ptr, int len)
{
    uint8_t receiveData[U1_BUFFER_SIZE];
    size_t i;
    for(i = 0; i < len; i++)
    {
        
        receiveData[i] = USART_ReceiveData(USART1);
        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET);
        if(USART_ReceiveData(USART1) == '\n')
        {
            break;
        }
    }
    return receiveData;
}
*/

__attribute__ ((used)) int _close(int file) {
    return -1;
}

__attribute__((weak)) int _getpid(void) {
    return 1;
}

__attribute__((weak)) int _kill(int pid, int sig) {
    errno = EINVAL;
    return -1;
}

__attribute__((weak)) void _exit(int status) {
    _kill(status, -1);
    while (1) {}        /* Make sure we hang here */
}

/** using malloc */
__attribute__((weak)) caddr_t _sbrk(int incr) {
    extern char end asm("end");
    static char *heap_end;
    char *prev_heap_end;

    if (heap_end == 0)
        heap_end = &end;

    prev_heap_end = heap_end;
    if (heap_end + incr > stack_ptr) {
//		write(1, "Heap and stack collision\n", 25);
//		abort();
        errno = ENOMEM;
        return (caddr_t) - 1;
    }

    heap_end += incr;

    return (caddr_t) prev_heap_end;
}

__attribute__((weak)) int _close(int file) {
    return -1;
}


__attribute__((weak)) int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}

__attribute__((weak)) int _isatty(int file) {
    return 1;
}

__attribute__((weak)) int _lseek(int file, int ptr, int dir) {
    return 0;
}

__attribute__((weak)) int _open(char *path, int flags, ...) {
    /* Pretend like we always fail */
    return -1;
}

__attribute__((weak)) int _wait(int *status) {
    errno = ECHILD;
    return -1;
}

__attribute__((weak)) int _unlink(char *name) {
    errno = ENOENT;
    return -1;
}

__attribute__((weak)) int _times(struct tms *buf) {
    return -1;
}

__attribute__((weak)) int _stat(char *file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}

__attribute__((weak)) int _link(char *old, char *new) {
    errno = EMLINK;
    return -1;
}

__attribute__((weak)) int _fork(void) {
    errno = EAGAIN;
    return -1;
}

__attribute__((weak)) int _execve(char *name, char **argv, char **env) {
    errno = ENOMEM;
    return -1;
}