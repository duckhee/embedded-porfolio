#include "platform_config.h"


uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    /** 1byte 로 키 여부 확인 */
    uint8_t bitStatus = 0x00;
    /** GPIO 포트의 핀 번호의 값이 리셋 값을 가질 경우 */
    if ((GPIOx->IDR & GPIO_Pin) != (uint32_t) Bit_RESET) {
        bitStatus = (uint8_t) Bit_SET;
    }
        /** GPIO 포트의 핀 번호의 값이 셋 값을 가질 경우 */
    else {
        bitStatus = (uint8_t) Bit_RESET;
    }
    return bitStatus;
}

void KEY_Test(void) {
    uint32_t i = 0;
    /** 모든 LED 끄기 */
    LED_Off_All();
    /** */
    while (1) {
        delay_100_milli_second();
        /** */
        if ((i++ & 0x1) == 0x00) {
            LED_On_Blue();
        }
            /** */
        else {
            LED_Off_Blue();
        }
        /** */
        if (GPIO_ReadInputDataBit(GPIO_KEY, GPIO_KEY1_PIN) == Bit_SET) {
            LED_On_Red();
        }
            /** */
        else {
            LED_Off_Red();
        }
        if (GPIO_ReadInputDataBit(GPIO_KEY, GPIO_KEY2_PIN) == Bit_SET) {
            LED_On_Yellow();
        }
            /** */
        else {
            LED_Off_Yellow();
        }
    }
}