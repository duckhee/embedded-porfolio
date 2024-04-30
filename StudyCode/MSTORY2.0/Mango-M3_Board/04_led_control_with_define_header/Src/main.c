#include "platform_config.h"


static void delay_int_count(volatile unsigned int nTime)
{
    for(; nTime > 0; nTime--);
}

void delay_1_second(void)
{
    delay_int_count(806596);
}

/** GPIO B Peripheral pin define mode and speed */
void GPIO_B_Output_Init(uint16_t pinNum, GPIOSpeed_t speedValE, GPIO_Output_Mode_t modeE) {
    /** speed value 와 mode 를 설정 -> 32bit 형태로 합쳐주기 */
    uint32_t tempValue = modeE << 2 | speedValE;
    /** pin 에 대한 위치를 저장하기 위한 변수 */
    uint32_t pinPos = 0x00;
    /** 하위 16bit 중 하나이면 낮은 값을 가지고 있는 핀 0 ~ 7 pin 중 하나이다. */
    if ((pinNum & 0xFF) != 0) {
        /** pin 의 위치를 찾기 위한 반복문 */
        for (pinPos = 0x00; pinPos < 0x08; pinPos++) {
            /** 입력 받은 pin 에 대하 위치 찾기 */
            if (pinNum == ((uint32_t) 0x01) << pinPos) {
                pinPos = pinPos * 4;
                /** 초기화 진행하는 코드 */
                GPIOB_CRL &= ~(0xF << pinPos);
                /** 값을 입력하는 코드 */
                CPIOB_CRL |= tempValue << pinPos;
                break;
            }
        }
    }
        /** 상위 16bit 중 하나이면 높은 값을 가지고 있는 핀 8 ~ 15 pin 중 하나이다. */
    else {
        pinNum = pinNum >> 8;
        /** pin 의 위치를 찾기 위한 반복문 */
        for (pinPos = 0x00; pinPos < 0x08; pinPos++) {
            /** 입력 받은 pin 에 대하 위치 찾기 */
            if (pinNum == ((uint32_t) 0x01) << pinPos) {
                pinPos = pinPos * 4;
                /** 초기화 진행하는 코드 */
                GPIOB_CRH &= ~(0xF << pinPos);
                /** 값을 입력하는 코드 */
                GPIOB_CRH |= tempValue << pinPos;
                break;
            }
        }
    };
}

int main(void) {

    RCC_APB2ENR |= RCC_APB2Periph_GPIOB;

    GPIO_B_Output_Init(GPIO_LED1_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_PP);
    GPIO_B_Output_Init(GPIO_LED2_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_PP);
    GPIO_B_Output_Init(GPIO_LED3_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_PP);

    LED_Test();

    while(1)
    {
        ;
    }
    return 0;
}
