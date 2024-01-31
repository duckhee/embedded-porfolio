#include "Hw_Config.h"
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "stm32f10x.h"

#define  U1_BUFFER_SIZE  100

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

__attribute__ ((used)) int _read(int fd, char *ptr, int len) {
    while ((USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET));
    return USART_ReceiveData(USART1);
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

/*
__attribute__ ((used)) int _read(int file, int ptr, int dir)
{
    #if 0
        init i;
        (void)file;

        for(i = 0; i < len; i++)
        {
            *ptr++ = USART_ReceiveData(USART1);
            while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
        }
    return len;
}
*/

__attribute__ ((used)) int _close(int file) {
    return -1;
}

//retargetting _read
/*
__attribute__ ((used)) int _read(int fd, char *buf, int len)
{
    size_t i;
    for(i = 0; i < len; i++)
    {
        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET);
        USART_Receive(USART1);
    }
    return len;
    for(fd = 0; fd < count; fd++)
    {
        while(pc_buffer_empty(&usart1_rx))
        {
            ;
        }
        disable_interruptes();
        pc_buffer_remove(&uart1_rx, (char *)buf++);
        enable_interrupts();
    }
    return count;
//    size_t i;
//    for(i = 0; i < len; ++i)
//    {
//        buf[i] = USART_ReceiveData(USART1);
//        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET);
//    }
//    return i;
}
*/
/*

//retargetting _read
__attribute__ ((used)) int _read(int __fd, void *__buf, size_t _nbyte)
{
    return 0;
}

int fgetc(FILE *f)
{
int c;

while (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == RESET);

c = LL_USART_ReceiveData8(huart1.Instance);

return fputc(c, f);
}

*/


/*
//need to testing 
__attribute__ ((used)) int _write(int fd, char *ptr, int len)
{
    size_t i;
    for(i = 0; i < len; i++)
    {
        fputc(USART1, (uint8_t *)&ch);
    }
    return len;
}

*/

/*
//int _read (int fd, const void *buf, size_t count)
//{
//  size_t CharCnt = 0x00;
 
//  (void)fd;                            /* Parameter is not used, suppress unused argument warning */
//  for (;count &gt; 0x00; --count) {
//    if ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR)  UART0_S1_RDRF_MASK) == 0x00) { /* Any data in receiver buffer */
/* Clear error flags */
//     UART0_PDD_ClearInterruptFlags(UART0_BASE_PTR,0x1FU);
//     if (CharCnt != 0x00) {           /* No, at least one char received? */
//       break;                         /* Yes, return received char(s) */
//     } else {                         /* Wait until a char is received */
//       while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR)  UART0_S1_RDRF_MASK) == 0x00) {};
//     }
//   }
//   CharCnt++;                         /* Increase char counter */
//   /* Save character received by UARTx device into the receive buffer */
//   *(uint8_t*)buf = (unsigned char)UART0_PDD_GetChar8(UART0_BASE_PTR);
//   /* Stop reading if CR (Ox0D) character is received */
//  if (*(uint8_t*)buf == 0x0DU) {     /* New line character (CR) received ? */
//     *(uint8_t*)buf = '\n';           /* Yes, convert LF to '\n' char. */
//     break;                           /* Stop loop and return received char(s) */
//   }
//   (uint8_t*)buf++;                   /* Increase buffer pointer */
// }
//return 1; /* WRONG! */
// return CharCnt;
//}
//*/