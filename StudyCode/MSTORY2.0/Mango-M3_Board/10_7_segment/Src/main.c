/*
 * (C) COPYRIGHT 2009 CRZ
 *
 * File Name : main.c
 * Author    : POOH
 * Version   : V1.0
 * Date      : 08/12/2009
 */

/* includes */

#include "platform_config.h"

/* functions */

static void delay_int_count(volatile unsigned int nTime) {
    for (; nTime > 0; nTime--);
}

void delay_1_second(void) {
    delay_int_count(806596);
}

void delay_100_milli_second(void) {
    delay_int_count(80660);
}

void USART_SendData(USART_TypeDef *USARTx, uint16_t Data) {
    /* Transmit Data */
    USARTx->DR = (Data & (uint16_t) 0x01FF);
}

uint16_t USART_ReceiveData(USART_TypeDef *USARTx) {
    /* Receive Data */
    return (uint16_t)(USARTx->DR & (uint16_t) 0x01FF);
}

FlagStatus USART_GetFlagStatus(USART_TypeDef *USARTx, uint16_t USART_FLAG) {
    FlagStatus bitstatus = RESET;

    if ((USARTx->SR & USART_FLAG) != (uint16_t) RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }
    return bitstatus;
}

void SerialPutChar(uint8_t c) {
    USART_SendData(USART1, c);
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void Serial_PutString(uint8_t *s) {
    while (*s != '\0') {
        SerialPutChar(*s);
        s++;
    }
}

typedef struct {
    uint32_t USART_BaudRate;            /*!< This member configures the USART communication baud rate.
                                           The baud rate is computed using the following formula:
                                            - IntegerDivider = ((PCLKx) / (16 * (USART_InitStruct->USART_BaudRate)))
                                            - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 16) + 0.5 */

    uint16_t USART_WordLength;          /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref USART_Word_Length */

    uint16_t USART_StopBits;            /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref USART_Stop_Bits */

    uint16_t USART_Parity;              /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref USART_Parity
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */

    uint16_t USART_Mode;                /*!< Specifies wether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref USART_Mode */

    uint16_t USART_HardwareFlowControl; /*!< Specifies wether the hardware flow control mode is enabled
                                           or disabled.
                                           This parameter can be a value of @ref USART_Hardware_Flow_Control */
} USART_InitTypeDef;

#define USART_WordLength_8b                  ((uint16_t)0x0000)
#define USART_WordLength_9b                  ((uint16_t)0x1000)

#define USART_StopBits_1                     ((uint16_t)0x0000)
#define USART_StopBits_0_5                   ((uint16_t)0x1000)
#define USART_StopBits_2                     ((uint16_t)0x2000)
#define USART_StopBits_1_5                   ((uint16_t)0x3000)

#define USART_Parity_No                      ((uint16_t)0x0000)
#define USART_Parity_Even                    ((uint16_t)0x0400)
#define USART_Parity_Odd                     ((uint16_t)0x0600)

#define USART_HardwareFlowControl_None       ((uint16_t)0x0000)
#define USART_HardwareFlowControl_RTS        ((uint16_t)0x0100)
#define USART_HardwareFlowControl_CTS        ((uint16_t)0x0200)
#define USART_HardwareFlowControl_RTS_CTS    ((uint16_t)0x0300)

#define USART_Mode_Rx                        ((uint16_t)0x0004)
#define USART_Mode_Tx                        ((uint16_t)0x0008)

#define HSI_Value                 ((uint32_t)8000000)

#define CR1_UE_Set                ((uint16_t)0x2000)  /*!< USART Enable Mask */

#define CR1_CLEAR_Mask            ((uint16_t)0xE9F3)  /*!< USART CR1 Mask */
#define CR2_STOP_CLEAR_Mask       ((uint16_t)0xCFFF)  /*!< USART CR2 STOP Bits Mask */
#define CR3_CLEAR_Mask            ((uint16_t)0xFCFF)  /*!< USART CR3 Mask */

void USART_Init(USART_TypeDef *USARTx, USART_InitTypeDef *USART_InitStruct) {
    uint32_t tmpreg = 0x00, apbclock = HSI_Value;
    uint32_t integerdivider = 0x00;
    uint32_t fractionaldivider = 0x00;

/*---------------------------- USART CR2 Configuration -----------------------*/
    tmpreg = USARTx->CR2;
    /* Clear STOP[13:12] bits */
    tmpreg &= CR2_STOP_CLEAR_Mask;
    /* Configure the USART Stop Bits, Clock, CPOL, CPHA and LastBit ------------*/
    /* Set STOP[13:12] bits according to USART_StopBits value */
    tmpreg |= (uint32_t) USART_InitStruct->USART_StopBits;

    /* Write to USART CR2 */
    USARTx->CR2 = (uint16_t) tmpreg;

/*---------------------------- USART CR1 Configuration -----------------------*/
    tmpreg = USARTx->CR1;
    /* Clear M, PCE, PS, TE and RE bits */
    tmpreg &= CR1_CLEAR_Mask;
    /* Configure the USART Word Length, Parity and mode ----------------------- */
    /* Set the M bits according to USART_WordLength value */
    /* Set PCE and PS bits according to USART_Parity value */
    /* Set TE and RE bits according to USART_Mode value */
    tmpreg |= (uint32_t) USART_InitStruct->USART_WordLength | USART_InitStruct->USART_Parity |
              USART_InitStruct->USART_Mode;
    /* Write to USART CR1 */
    USARTx->CR1 = (uint16_t) tmpreg;

/*---------------------------- USART CR3 Configuration -----------------------*/
    tmpreg = USARTx->CR3;
    /* Clear CTSE and RTSE bits */
    tmpreg &= CR3_CLEAR_Mask;
    /* Configure the USART HFC -------------------------------------------------*/
    /* Set CTSE and RTSE bits according to USART_HardwareFlowControl value */
    tmpreg |= USART_InitStruct->USART_HardwareFlowControl;
    /* Write to USART CR3 */
    USARTx->CR3 = (uint16_t) tmpreg;

/*---------------------------- USART BRR Configuration -----------------------*/
    /* Configure the USART Baud Rate -------------------------------------------*/
    /* Determine the integer part */
    integerdivider = ((0x19 * apbclock) / (0x04 * (USART_InitStruct->USART_BaudRate)));
    tmpreg = (integerdivider / 0x64) << 0x04;
    /* Determine the fractional part */
    fractionaldivider = integerdivider - (0x64 * (tmpreg >> 0x04));
    tmpreg |= ((((fractionaldivider * 0x10) + 0x32) / 0x64)) & ((uint8_t) 0x0F);
    /* Write to USART BRR */
    USARTx->BRR = (uint16_t) tmpreg;
}

void USART1_Init(void) {
    USART_InitTypeDef USART_InitStructure;

    /* USARTx configuration ------------------------------------------------------*/
    /* USARTx configured as follow:
     - BaudRate = 115200 baud  
     - Word Length = 8 Bits
     - One Stop Bit
     - No parity
     - Hardware flow control disabled (RTS and CTS signals)
     - Receive and transmit enabled
     */
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl
            = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    /* Configure the USARTx */
    USART_Init(USART1, &USART_InitStructure);

    /* Enable the USART1 */
    USART1->CR1 |= CR1_UE_Set;
}

void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct) {
    uint32_t currentmode = 0x00, currentpin = 0x00, pinpos = 0x00, pos = 0x00;
    uint32_t tmpreg = 0x00, pinmask = 0x00;

/*---------------------------- GPIO Mode Configuration -----------------------*/
    currentmode = ((uint32_t) GPIO_InitStruct->GPIO_Mode) & ((uint32_t) 0x0F);
    if ((((uint32_t) GPIO_InitStruct->GPIO_Mode) & ((uint32_t) 0x10)) != 0x00) {
        /* Output mode */
        currentmode |= (uint32_t) GPIO_InitStruct->GPIO_Speed;
    }
/*---------------------------- GPIO CRL Configuration ------------------------*/
    /* Configure the eight low port pins */
    if (((uint32_t) GPIO_InitStruct->GPIO_Pin & ((uint32_t) 0x00FF)) != 0x00) {
        tmpreg = GPIOx->CRL;
        for (pinpos = 0x00; pinpos < 0x08; pinpos++) {
            pos = ((uint32_t) 0x01) << pinpos;
            /* Get the port pins position */
            currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;
            if (currentpin == pos) {
                pos = pinpos << 2;
                /* Clear the corresponding low control register bits */
                pinmask = ((uint32_t) 0x0F) << pos;
                tmpreg &= ~pinmask;
                /* Write the mode configuration in the corresponding bits */
                tmpreg |= (currentmode << pos);
                /* Reset the corresponding ODR bit */
                if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD) {
                    GPIOx->BRR = (((uint32_t) 0x01) << pinpos);
                } else {
                    /* Set the corresponding ODR bit */
                    if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU) {
                        GPIOx->BSRR = (((uint32_t) 0x01) << pinpos);
                    }
                }
            }
        }
        GPIOx->CRL = tmpreg;
    }
/*---------------------------- GPIO CRH Configuration ------------------------*/
    /* Configure the eight high port pins */
    if (GPIO_InitStruct->GPIO_Pin > 0x00FF) {
        tmpreg = GPIOx->CRH;
        for (pinpos = 0x00; pinpos < 0x08; pinpos++) {
            pos = (((uint32_t) 0x01) << (pinpos + 0x08));
            /* Get the port pins position */
            currentpin = ((GPIO_InitStruct->GPIO_Pin) & pos);
            if (currentpin == pos) {
                pos = pinpos << 2;
                /* Clear the corresponding high control register bits */
                pinmask = ((uint32_t) 0x0F) << pos;
                tmpreg &= ~pinmask;
                /* Write the mode configuration in the corresponding bits */
                tmpreg |= (currentmode << pos);
                /* Reset the corresponding ODR bit */
                if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD) {
                    GPIOx->BRR = (((uint32_t) 0x01) << (pinpos + 0x08));
                }
                /* Set the corresponding ODR bit */
                if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU) {
                    GPIOx->BSRR = (((uint32_t) 0x01) << (pinpos + 0x08));
                }
            }
        }
        GPIOx->CRH = tmpreg;
    }
}

void GPIO_Configuration(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    // UART configuration ...

    /* Configure USARTx_Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin = GPIO_USART_Tx_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIO_USART, &GPIO_InitStructure);

    /* Configure USARTx_Rx as input floating */
    GPIO_InitStructure.GPIO_Pin = GPIO_USART_Rx_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIO_USART, &GPIO_InitStructure);

    // Key configuration ...

    /* Configure gpio as input : Button Left-WKUP */
    GPIO_InitStructure.GPIO_Pin = GPIO_KEY1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIO_KEY, &GPIO_InitStructure);

    /* Configure gpio as input : Button Right-USER */
    GPIO_InitStructure.GPIO_Pin = GPIO_KEY2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIO_KEY, &GPIO_InitStructure);

    // LED configuration ...

    /* Configure gpio as output : LED1, LED2, LED3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_LED1_PIN | GPIO_LED2_PIN | GPIO_LED3_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIO_LED, &GPIO_InitStructure);
}

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE {
    /* Write a character to the USART */
    if (ch == '\n') {
        USART_SendData(USART1, '\r');
        while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
        USART_SendData(USART1, '\n');
    } else {
        USART_SendData(USART1, (uint8_t) ch);
    }

    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

    return ch;
}

uint8_t USART_GetCharacter(USART_TypeDef *usart_p) {
    uint8_t data;

    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(usart_p, USART_FLAG_RXNE) == RESET);

    /* Write a character to the USART */
    data = USART_ReceiveData(usart_p);

    USART_SendData(usart_p, data);
    while (USART_GetFlagStatus(usart_p, USART_FLAG_TXE) == RESET);

    if (data == '\r') return (int) ('\n');
    else return (data);
}

void System_Information() {
    printf("USART1->BRR : 0x%08X\n", USART1->BRR);
}

/*
 * Name   : main
 * Input  : None
 * Output : None
 * Return : None
 */
int main(void) {
    uint8_t ch;

    RCC->APB2ENR |= RCC_APB2Periph_GPIOA;
    RCC->APB2ENR |= RCC_APB2Periph_GPIOB;
    RCC->APB2ENR |= RCC_APB2Periph_USART1;

    GPIO_Configuration();

    USART1_Init();

    while (1) {
        printf("\n---------------------\n");
        printf("Press menu key\n");
        printf("---------------------\n");
        printf("0> System Information\n");
        printf("---------------------\n");
        printf("1> LED Test\n");
        printf("2> KEY Test\n");
        printf("3> 7-Segment Test\n");
        printf("---------------------\n");
        printf("x> quit\n\n");

        ch = USART_GetCharacter(USART1);
//        scanf("%d", &ch);
        printf("value ch : %d\r\n", ch);
        printf(" is selected\n\n");

        switch ((char) ch) {
            case '0':
                System_Information();
                break;

            case '1':
                LED_Test();
                break;

            case '2':
                KEY_Test();
                break;

            case '3':
                Seven_Segment_Test();
                break;
        }

        if ('x' == (char) ch) {
            break;
        }
    }
}

/** arm-none-eabi-gcc 를 사용할 떄는 이 부분을 재정의 해줘야한다. */
__attribute__((used)) int _write(int fd, char *ptr, int len) {
    size_t i;
    for (i = 0; i < len; i++) {
        USART_SendData(USART1, ptr[i]);
        while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    }
    return len;
}

