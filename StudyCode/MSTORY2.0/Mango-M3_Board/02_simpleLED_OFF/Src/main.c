#include "platform_config.h"

/** 
 * volatile 는 최적화를 하지 말라는 지시어 효과와 값이 무엇인지 모르기 때문에 volatile 로 선언된 변수들을 계산할 때 순서등 명확히 명시 해줘야 한다.
*/
static void delay_int_counter(volatile unsigned int nTime){
    /** embedded 에서는 감소 시키는 코드가 조금 더 성능이 좋은 형태를 가진다. -> 스택의 주소가 감소하는 것과 같은 동작 */
    for(; nTime > 0; nTime--);
}

int main() {
    /** RCC 설정 */
    /** APB2 Peripheral clock enable register(RCC_APB2ENR) */
    /** RCC I/O PortB Enable */
    /** RCC_APB2ENR */
    (*(volatile unsigned *) 0x40021018) |= 0x8; /** IOPB EN 0x8 */

     /** Pin9 General purpose output push-pull Mode Output mode, Max speed 10MHz */
   (*(volatile unsigned *)0x40010C04) |= 0x10;
    /** Pin9 General purpose output Open-drain Mode Output mode, Max speed 10MHz */
//    (*(volatile unsigned *)0x40010C04) |= 0x50;
    /** Pin9 Alternate function output Push-pull Mode Output mode, Max speed 10MHz */
//    (*(volatile unsigned *)0x40010C04) |= 0x90;
    /** Pin9 Alternate function output Open-drain Mode Output mode, Max speed 10MHz */
//     (*(volatile unsigned *) 0x40010C04) |= 0xD0;
         /**
         * GPIO CNFy Mode
         * 00: Input mode (reset state)
         * 01: Output mode, max speed 10 MHz.
         * 10: Output mode, max speed 2 MHz.
         * 11: Output mode, max speed 50 MHz.
         */
        /**
         * 00: General purpose output push-pull
         * 01: General purpose output Open-drain
         * 10: Alternate function output Push-pull
         * 11: Alternate function output Open-drain
         */
    /** Port configuration register high (GPIOx_CRH) (x=A..G) = 0x40010C04 */
    /** Mode Output CNFy General purpose output push-pull */
    (*(volatile unsigned *)0x40010C04) |= 0x10; // 0001 0000
    /** GPIO B Port 에 대해서 사용을 하기 위한 GPIOB 를 사용하는 것 -> 0x40021018 register에 0x8 or 연산을 통해 사용할 포트웨 대한 enable 설정 */
    (*(volatile unsigned *)0x40010C04) |= 0x10;
    /** GPIOB Port Pin 9 RESET Setting GPIO LOW */
/** RED LED와 연결되어 있는 Pin에 대해서 쓰기 작업 진행 -> LED 를 작동 시키기 위한 Off  */
    (*(volatile unsigned *)0x40010C14) |= 0x200;
    delay_int_counter(10000);
    /** GPIOB Port Pin 9 SET Setting GPIO HIGH */
/** RED LED와 연결되어 있는 Pin에 대해서 쓰기 작업 진행 -> LED 를 작동 끄기 위한 On */
    (*(volatile unsigned *)0x40010C10) |= 0x200;
    while(1){
        ;
    }
    return 0;
}