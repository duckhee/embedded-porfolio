#include "platform_config.h"

void LED_On_Red(void);

void LED_Off_Red(void);

void LED_On_Yellow(void);

void LED_Off_Yellow(void);

void LED_On_Blue(void);

void LED_Off_Blue(void);

void LED_On_All(void);

void LED_Off_All(void);

void LED_OnOffAll_Multi(uint32_t count);

void LED_Test(void);


void LED_On_Red(void) {
    /** set led 1 pin */
    GPIOB_BRR |= GPIO_LED1_PIN;
}

void LED_Off_Red(void) {
    /** reset led 1 pin */
    GPIOB_BSRR |= GPIO_LED1_PIN;
}

void LED_On_Yellow(void) {
    GPIOB_BRR |= GPIO_LED2_PIN;
}

void LED_Off_Yellow(void) {
    GPIOB_BSRR |= GPIO_LED2_PIN;
}

void LED_On_Blue(void) {
    GPIOB_BRR |= GPIO_LED3_PIN;
}

void LED_Off_Blue(void) {
    GPIOB_BSRR |= GPIO_LED3_PIN;
}


void LED_On_All(void) {
    LED_On_Red();
    LED_On_Yellow();
    LED_On_Blue();
}

void LED_Off_All(void) {
    LED_Off_Red();
    LED_Off_Yellow();
    LED_Off_Blue();
}

void LED_OnOffAll_Multi(uint32_t count) {
    for (; count > 0; count--) {
        LED_Off_Red();
        LED_On_Yellow();
        LED_On_Blue();
        delay_1_second();

        LED_On_Red();
        LED_Off_Yellow();
        LED_On_Blue();
        delay_1_second();

        LED_On_Red();
        LED_On_Yellow();
        LED_Off_Blue();
        delay_1_second();
    }
    LED_Off_All();
}

void LED_Test(void) {
#if 0
    LED_On_All();
    delay_1_second();
    LED_Off_All();
    delay_1_second();
    LED_On_All();
#else
    LED_OnOffAll_Multi(30);
#endif
}