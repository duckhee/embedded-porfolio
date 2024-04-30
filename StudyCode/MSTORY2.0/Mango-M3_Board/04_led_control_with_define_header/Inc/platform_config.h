#ifndef __MANGO_M3_H__
#define __MANGO_M3_H__

#include <stdint.h>

/** gpio speed define enum */
typedef enum {
    GPIO_Speed_10MHz = 1,
    GPIO_Speed_2MHz,
    GPIO_Speed_50MHz
} GPIOSpeed_t;

/** gpio mode define  */
typedef enum {
    GPIO_Mode_Out_PushPull = 0x00,
    GPIO_Mode_Out_OpenDrain = 0x01,
    GPIO_Mode_AF_PushPull = 0x10,
    GPIO_Mode_AF_OpenDrain = 0x11
} GPIO_Output_Mode_t;

/** GPIO Pin Define */
#define GPIO_Pin_0              ((uint16_t) 0x0001)
#define GPIO_Pin_1              ((uint16_t) 0x0002)
#define GPIO_Pin_2              ((uint16_t) 0x0004)
#define GPIO_Pin_3              ((uint16_t) 0x0008)
#define GPIO_Pin_4              ((uint16_t) 0x0010)
#define GPIO_Pin_5              ((uint16_t) 0x0020)
#define GPIO_Pin_6              ((uint16_t) 0x0040)
#define GPIO_Pin_7              ((uint16_t) 0x0080)
#define GPIO_Pin_8              ((uint16_t) 0x0100)
#define GPIO_Pin_9              ((uint16_t) 0x0200)
#define GPIO_Pin_10             ((uint16_t) 0x0400)
#define GPIO_Pin_11             ((uint16_t) 0x0800)
#define GPIO_Pin_12             ((uint16_t) 0x1000)
#define GPIO_Pin_13             ((uint16_t) 0x2000)
#define GPIO_Pin_14             ((uint16_t) 0x4000)
#define GPIO_Pin_15             ((uint16_t) 0x8000)
#define GPIO_Pin_All            ((uint16_t) 0xFFFF)


#define GPIO_LED1_PIN           GPIO_Pin_9      /** RED LED */
#define GPIO_LED2_PIN           GPIO_Pin_5      /** YELLOW LED */
#define GPIO_LED3_PIN           GPIO_Pin_8      /** BLUE LED */


/** RCC Port define */
#define RCC_APB2Periph_AFIO        ((uint32_t)0x00000001)
#define RCC_APB2Periph_GPIOA       ((uint32_t)0x00000004)
#define RCC_APB2Periph_GPIOB       ((uint32_t)0x00000008)
#define RCC_APB2Periph_GPIOC       ((uint32_t)0x00000010)
#define RCC_APB2Periph_GPIOD       ((uint32_t)0x00000020)
#define RCC_APB2Periph_GPIOE       ((uint32_t)0x00000040)
#define RCC_APB2Periph_GPIOF       ((uint32_t)0x00000080)
#define RCC_APB2Periph_GPIOG       ((uint32_t)0x00000100)
#define RCC_APB2Periph_ADC1        ((uint32_t)0x00000200)
#define RCC_APB2Periph_ADC2        ((uint32_t)0x00000400)
#define RCC_APB2Periph_TIM1        ((uint32_t)0x00000800)
#define RCC_APB2Periph_SPI1        ((uint32_t)0x00001000)
#define RCC_APB2Periph_TIM8        ((uint32_t)0x00002000)
#define RCC_APB2Periph_USART1      ((uint32_t)0x00004000)
#define RCC_APB2Periph_ADC3        ((uint32_t)0x00008000)

#define RCC_APB2ENR                (*(volatile unsigned *)0x40021018)

#define GPIOB_CRL                  (*(volatile unsigned *)0x40010C00)
#define GPIOB_CRH                  (*(volatile unsigned *)0x40010C04)

#define GPIOB_BSRR                 (*(volatile unsigned *)0x40010C10)
#define GPIOB_BRR                  (*(volatile unsigned *)0x40010C14)

/* functions */

void LED_Test (void);
void delay_1_second(void);

#endif