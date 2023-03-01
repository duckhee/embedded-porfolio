#include "mango_m3.h"

// software delay time
void soft_delay_int(volatile unsigned int delayTime) {
    for (; delayTime > 0; delayTime--);
}

// tick cal 1 sec
void delay_one_sec() {
    soft_delay_int(806596);
}

int main() {
    /** APB2 Peripheral clock enable register(RCC_APB2ENR) */
    /** RCC I/O PortB Enable */
    /** RCC_APB2ENR */
    (*(volatile unsigned *) 0x40021018) |= 0x8; /** IOPB EN 0x8 */
# if 0
    (*(volatile unsigned *)0x40010C04) |= 0x10;
#else
    /** PortB RESET(HIGHT) */
    /**  GPIO_CRH */
    /** 9Pin RESET 0 */
    (*(volatile unsigned *)0x40010C04) &= 0xFFFFFF0F;
    /** Pin9 General purpose output push-pull Mode Output mode, Max speed 10MHz */
//    (*(volatile unsigned *)0x40010C04) |= 0x10;
    /** Pin9 General purpose output Open-drain Mode Output mode, Max speed 10MHz */
//    (*(volatile unsigned *)0x40010C04) |= 0x50;
    /** Pin9 Alternate function output Push-pull Mode Output mode, Max speed 10MHz */
//    (*(volatile unsigned *)0x40010C04) |= 0x90;
    /** Pin9 Alternate function output Open-drain Mode Output mode, Max speed 10MHz */
    (*(volatile unsigned *)0x40010C04) |= 0xD0;
    /** PortB RESET(LOW) */
    /**  GPIO_CRL */
    (*(volatile unsigned *)0x40010C00) &= 0xFF0FFFFF;
    /** LED YELLOW PIN5 ON */
    //(*(volatile unsigned *)0x40010C00) |= 0x100000;
    /** LED RED ON */
    /** Pin 9 */
    //(*(volatile unsigned *)0x40010C04) |= 0x10;
    /** GPIO PIN9 RESET */
    //(*(volatile unsigned *)0x40010C14) |= 0x200;
    delay_one_sec();
    /** GPIO PIN9 SET */
    //(*(volatile unsigned *)0x40010C10) |= 0x200;
    /** LED BLUE ON */
    /** GPIO PIN8 SET */
    //(*(volatile unsigned *)0x40010C04) |= 0x1;
//    (*(volatile unsigned *)0x40010C04) |= 0x50;
//    (*(volatile unsigned *)0x40010C04) |= 0x90;
//    (*(volatile unsigned *)0x40010C04) |= 0xD0;

#endif
    while (1) { ;
    }
    return 0;
}