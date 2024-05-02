#include "platform_config.h"


static void delay_int_count(volatile unsigned int nTime) {
    for (; nTime > 0; nTime--);
}

void delay_1_second(void) {
    delay_int_count(806596);
}

void delay_100_milli_second(void) {
    delay_int_count(80660);
}

void GPIO_Port_Init(GPIO_TypeDef *GPIOx, uint16_t pinNum, GPIOSpeed_t speedValE, uint32_t modeE) {
    /** speed value 와 mode 를 설정 -> 32bit 형태로 합쳐주기 */
    uint32_t tmpVal = modeE << 2 | speedValE;
    /** pin 에 대한 위치를 저장하기 위한 변수 */
    uint32_t pinpos = 0x00;

    // pin #0 ~ #7
    if ((pinNum & 0xFF) != 0) {
        for (pinpos = 0x00; pinpos < 0x08; pinpos++) {
            if (pinNum == ((uint32_t) 0x01) << pinpos) {
                pinpos = pinpos * 4;
                GPIOx->CRL &= ~(0xF << pinpos);
                GPIOx->CRL |= tmpVal << pinpos;
                break;
            }
        }
    }
        // pin #8 ~ #15
    else {
        pinNum = pinNum >> 8;
        for (pinpos = 0x00; pinpos < 0x08; pinpos++) {
            if (pinNum == ((uint32_t) 0x01) << pinpos) {
                pinpos = pinpos * 4;
                GPIOx->CRH &= ~(0xF << pinpos);
                GPIOx->CRH |= tmpVal << pinpos;
                break;
            }
        }
    }
}

int main(void) {
    /** 버튼이 연결 되어 있는 포트 */
    RCC->APB2ENR |= RCC_APB2Periph_GPIOA;
    /** LED 가 연결 되어 있는 포트 */
    RCC->APB2ENR |= RCC_APB2Periph_GPIOB;
    /** LED 사용 설정 */
    GPIO_Port_Init(GPIO_LED, GPIO_LED1_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_PushPull);
    GPIO_Port_Init(GPIO_LED, GPIO_LED2_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_PushPull);
    GPIO_Port_Init(GPIO_LED, GPIO_LED3_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_PushPull);
    /** KEY 사용 설정 */
    GPIO_Port_Init(GPIO_KEY, GPIO_KEY1_PIN, GPIO_Input_Mode, GPIO_Mode_IN_FLOATING);
    GPIO_Port_Init(GPIO_KEY, GPIO_KEY2_PIN, GPIO_Input_Mode, GPIO_Mode_IN_FLOATING);
    KEY_Test();
    while (1);
    return 0;
}