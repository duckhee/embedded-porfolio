#include "mango_m3.h"


static void delay_int_count(volatile unsigned int nTime){
    for(; nTime > 0;nTime--);
}

void delay_1_second(void);

int main(){
 /** GPIOB Port Enable Clock Init */
    (*(volatile unsigned long *)0x40021018) |= 0x8;
    /** GPIOB Port Pin 5 Init Setting */
    (*(volatile unsigned long *)0x40010C00) &= 0xFF0FFFFF;
    /** GPIOB Port Pin 5 Output Mode Setting */
    /** GPIOB Port Pin5 Output mode, max speed 10 MHz. */
    (*(volatile unsigned long *)0x40010C00) |= 0x100000;
    /** GPIOB Port Pin 8, 9 Init Setting */
    (*(volatile unsigned long *)0x40010C04) &= 0xFFFFFF00;
    /** GPIOB Port Pin9 Output mode, max speed 10 MHz. */
    (*(volatile unsigned long *)0x40010C04) |= 0x10;
    /** GPIOB Port Pin8 Output mode, max speed 10 MHz. */
    (*(volatile unsigned long *)0x40010C04) |= 0x1;
    /** GPIOB Port Pin 9 RESET Setting */
    (*(volatile unsigned long *)0x40010C14) |= 0x200;
    delay_1_second();
    /** GPIOB Port Pin 9 SET Setting */
    (*(volatile unsigned long *)0x40010C10) |= 0x200;
    delay_1_second();
    /** GPIOB Port Pin 8 RESET Setting */
    (*(volatile unsigned long *)0x40010C14) |= 0x100;
    delay_1_second();
    /** GPIOB Port Pin 8 SET Setting */
    (*(volatile unsigned long *)0x40010C10) |= 0x100;
    delay_1_second();
    /** GPIOB Port Pin 5 RESET Setting */
    (*(volatile unsigned long *)0x40010C14) |= 0x20;
    delay_1_second();
    /** GPIOB Port Pin 5 SET Setting */
    (*(volatile unsigned long *)0x40010C10) |= 0x20;
    while(1){
        ;
    }
    return 0;
}

void delay_1_second(void){
    delay_int_count(806596);
}

