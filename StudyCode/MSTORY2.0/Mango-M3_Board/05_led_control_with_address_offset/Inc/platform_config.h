#ifndef __PLATFORM_CONFIG_H__
#define __PLATFORM_CONFIG_H__

#include <stdint.h>

/** */
#define __IO                    volatile

/** gpio speed define enum */
typedef enum {
    GPIO_Input_Mode = 0,
    GPIO_Speed_10MHz = 1,
    GPIO_Speed_2MHz,
    GPIO_Speed_50MHz
} GPIOSpeed_t;

/** gpio input mode define  */
typedef enum {
    GPIO_Mode_AnalogInput = 0x00,
    GPIO_Mode_IN_FLOATING = 0x01,
    GPIO_Mode_InPutDPullUp = 0x10
} GPIO_Input_Mode_t;

/** gpio output mode define  */
typedef enum {
    GPIO_Mode_Out_PushPull = 0x00,
    GPIO_Mode_Out_OpenDrain = 0x01,
    GPIO_Mode_AF_PushPull = 0x10,
    GPIO_Mode_AF_OpenDrain = 0x11
} GPIO_Output_Mode_t;

/** RCC structure */
/** 32bit 는 4byte 이므로 주소 값에서 4만큼 떨어지게 되므로 구조체에서 32bit 형태로 선언 하는 것이다. */
typedef struct {
    __IO uint32_t CR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t APB2RSTR;
    __IO uint32_t APB1RSTR;
    __IO uint32_t AHBENR;
    __IO uint32_t APB2ENR;
    __IO uint32_t APB1ENR;
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
#ifdef STM32F10X_CL
    __IO uint32_t AHBRSTR;
    __IO uint32_t CFGR2;
#endif
} RCC_TypeDef;

/** GPIO Structure */
typedef struct {
    __IO uint32_t CRL;
    __IO uint32_t CRH;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t BRR;
    __IO uint32_t LCKR;
} GPIO_TypeDef;

/** Peripheral Memory Map */
#define PERIPH_BASE             ((uint32_t) 0x40000000)
/** Peripheral Memory Map */
#define APB1PERIPH_BASE         PERIPH_BASE
#define APB2PERIPH_BASE         (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE          (PERIPH_BASE + 0x20000)

#define RCC_BASE                (AHBPERIPH_BASE + 0x1000)
/** RCC 에 대한 구조체 형태로 해당 메모리 위치 부터 메모리 구조 읽기 */
#define RCC                     ((RCC_TypeDef *)RCC_BASE)

/** GPIO 에 대한 포트를 Memory Mapping -> using Address Offset */
#define GPIOA_BASE              (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE              (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE              (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE              (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE              (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE              (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE              (APB2PERIPH_BASE + 0x2000)

#define GPIOA                   ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                   ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                   ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                   ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE                   ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF                   ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG                   ((GPIO_TypeDef *) GPIOG_BASE)

/** LED Port Define */
#define GPIO_LED                GPIOB
/** Button Port Define */
#define GPIO_KEY                GPIOA
/** LEFT WakeUp Button */
#define GPIO_KEY1_PIN           GPIO_Pin_0
/** RIGHT User Key Button */
#define GPIO_KEY2_PIN           GPIO_Pin_1

/** Peripheral Port Define */
#define RCC_APB2ENR             (*(volatile unsigned *)0x40021018)
#define GPIOB_CRL               (*(volatile unsigned *)0x40010C00)
#define GPIOB_CRH               (*(volatile unsigned *)0x40010C04)
#define GPIOB_BSRR              (*(volatile unsigned *)0x40010C10)
#define GPIOB_BRR               (*(volatile unsigned *)0x40010C14)

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

void LED_Test(void);

void delay_1_second(void);


#endif