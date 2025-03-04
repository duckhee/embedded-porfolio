/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "can.h"
#include "dma.h"
#include "fatfs.h"
#include "i2c.h"
#include "lwip.h"
#include "sdio.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "CLCD.h"
#include "7SEG.h"
#include "MP3Sample.h"
#include "VS1003.h"
#include <math.h>
#include "udp_echoserver.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */


/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t rx_data;
uint8_t Sw1_Flag = 0, Sw2_Flag = 0, Sw3_Flag = 0, Sw4_Flag = 0;
/** UDP 수신이 되었는지를 확인하는 flag */
extern uint8_t udp_flag;
extern uint8_t udpData;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */
int _write(int fd, char *ptr, int len){
	HAL_UART_Transmit(&huart3, (char *)&ptr, len, 0xFF);
	return len;
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART3_UART_Init();
  MX_TIM7_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM10_Init();
  MX_TIM5_Init();
  MX_TIM2_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_SPI2_Init();
  MX_SDIO_SD_Init();
  MX_FATFS_Init();
  MX_LWIP_Init();
  MX_CAN1_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */
  CLCD_GPIO_Init();

     /** LCD Initialized */
     CLCD_Init();

     /** LCD x position, y position and write str */
     CLCD_Puts(0, 0, "Welcome to ");
     CLCD_Puts(0, 1, "M-Hive");
     CLCD_Clear();
     /** UART3 IT Initialized */
    HAL_UART_Receive_IT(&huart3, &rx_data, 1);

     /** Timer 에 대한 시작을 알리는 함수 실행 */
     HAL_TIM_Base_Start_IT(&htim7);

     _7SEG_GPIO_Init();

     /** PWM에 대한 신호를 만들기 위해서 실행을 하는 함수 */
     HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
     HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
     HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);

     HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
     HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
     HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);

     /** PWM 신호를 발생을 시키기 위한 함수 */
     HAL_TIM_PWM_Start(&htim10, TIM_CHANNEL_1);
     /** passive buzzer 동작 */
//     HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
     /** Motor를 동작 시키기 위한 PWM 활성화 */
     HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
     HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);

     /** 모터에 대한 동작 방향을 변경을 하기 위한 Pulse width 변경 */
     TIM5->CCR1 = 0;
     TIM5->CCR4 = 5000;
     /** pulse width 를 변경하기 위한 변수 */
     uint16_t ccrValue = 0;
     /** 0.2ms => 100 , 3ms => 1500 */
     uint16_t servoValue = 100;
     /** buzzer 에 대한 펄스의 주기 변경 */
//     TIM2->ARR = 500;
  //   TIM2->CCR1 = 250;
//     TIM2->CCR1 = TIM2->ARR / 2;
     /** 주기를 변경을 하면서 Buzzer에 대한 음 변경 variable */
     /** 1000 -> 500Hz */
     uint16_t arrValue = 1000;
     /** 증가 감소 설정 변수 */
     uint8_t ud_flag = 0;

     uint16_t prescalerValue = 1000-1;
     /** 출력하기 위한 값을 담아줄 템플릿 변수 */
     uint8_t str[20];
     /** ADC에 대한 값을 저장하기 위한 변수 */
     volatile uint32_t adcValue[4] = {0};
     /** ADC를 이용하기 위해서 호출 하는 함수 */
     HAL_ADC_Start_DMA(&hadc1, &adcValue[0], 4);


     /** EEPROM에 쓸 값을 담을 변수 및 읽어올 때 담아줄 변수 */
     uint8_t eepRom[10] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x88, 0x99};

     /** I2C를 이용해서 데이터 쓰기 */
     HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0x00, I2C_MEMADD_SIZE_8BIT, &eepRom[0], 10, 10);

     /** 완료까지 시간이 걸리기 때문에 Delay 지정 */
     HAL_Delay(3);

     /** 변수에 대한 데이터 초기화 */
     for(int i = 0;i < 10; ++i){
    	 eepRom[i] = 0x00;
     }

     /** 데이터 읽어오기 -> I2C를 이용한 읽기 */
     HAL_I2C_Mem_Read(&hi2c1, 0xA0, 00, I2C_MEMADD_SIZE_8BIT, &eepRom[0], 10, 10);
     sprintf(str, "%02x 02x 02x 02x 02x", eepRom[0], eepRom[1], eepRom[2], eepRom[3], eepRom[4]);
     CLCD_Puts(0, 0, str);
     sprintf(str, "%02x 02x 02x 02x 02x", eepRom[5], eepRom[6], eepRom[7], eepRom[8], eepRom[9]);
     CLCD_Puts(0, 1, str);

     /** VS1003 초기화 -> SPI 초기화 */
     VS1003_Init();
     /** Codec에 대한 초기화 */
     VS1003_SoftReset();

     /** 오디오 데이터를 32byte씩 전송하기 위한 변수 */
     int idx = 0;
     /** SD Card에 쓰기 위한 텍스트 */
     BYTE buf[32] = "Hello World";
     unsigned char readBuffer[32] = {0};
     uint32_t bw, br;
     /** SD Card에 대한 Mount */
//     if((retSD = f_mount(&SDFatFS, "0:/", 1)) == FR_OK){
     if((retSD = f_mount(&SDFatFS, &SDPath[0], 1)) == FR_OK){
    	 sprintf(str, "f_mount OK : %d", retSD);
    	 CLCD_Puts(0, 0, str);
     }else{
    	 sprintf(str, "f mount Failed %d",retSD);
    	 CLCD_Puts(0, 0, str);
     }

     /** 파일에 대한 목록을 가져오는 코드 */
     /** 폴더에 대한 구조체 */
     DIR dir;
     /** FILE에 대한 정보 가져오기 위한 구조체 */
     FILINFO fileInfo;
     /** file에 대한 개수를 저장할 변수 */
     uint16_t fileCnt = 0;
     if((retSD = f_opendir(&dir, "0:/")) == FR_OK){
    	 /** 반복문을 통한 파일 이름 읽어오기 */
    	 while(1){
    		 /** 폴더에 있는 파일 정보 가져오기 */
    		 retSD = f_readdir(&dir, &fileInfo);
    		 /** 파일의 정보가 더이상 없을 경우 */
    		 if(dir.sect == 0){
    			 break;
    		 }
    		 printf("%s\t0x%x\n", fileInfo.fname, fileInfo.fattrib);
    		 fileCnt++;
    	 }
     }else{
    	 printf("The file/directory Object is invalid! %d\n", retSD);
     }
     printf("Total %d file(s)... \r\n", fileCnt);
     /** file name 1.mp3 open */
     unsigned char filename[20] = "0:/1.mp3";
     uint16_t mp3_idx = 0;

     /** 파일 열기 */
     if((retSD = f_open(&SDFile, filename, FA_OPEN_EXISTING | FA_READ)) == FR_OK){
    	 	CLCD_Clear();
    	 	sprintf(str, "%s opened", filename);
    	 	CLCD_Puts(0, 0, str);
     }
     /** 파일 열기 실패 시 */
     else{
    	 CLCD_Clear();
    	 sprintf(str, "open error %d\n", retSD);
    	 CLCD_Puts(0, 0, str);
     }

     /** 음원 파일에 대한 출력 및 일시정지를 표현하기 위한 변수 */
     uint8_t pp_flag = 0;

     /** UDP 에 대한 서버 설정 */
//     udp_echoserver_init();

     /* Notify user about the network interface config */
//     User_notification(&gnetif);
     /** CAN에 대한 사용을 하기 위한 시작 함수 */
     HAL_CAN_Start(&hcan1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  if(Sw1_Flag){
		  Sw1_Flag = 0;
		  /* txHeader 에 대한 구성 */
		  canTxHeader.StdId = 0x102;
		  canTxHeader.RTR = CAN_RTR_DATA;
		  canTxHeader.IDE = CAN_ID_STD;
		  canTxHeader.DLC = 8;

		  /** 데이터에 대한 정의 */
		  for(int i = 0; i < 8; ++i){
			  can1Tx0Data[i] ++;
		  }
		  /** 전송을 할 수 있는지 확인 */
		  TxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan1);
		  /** data 전송 */
		  HAL_CAN_AddTxMessage(&hcan1, &canTxHeader, &can1Tx0Data[0], &TxMailBox);

	  }
	  if(Sw2_Flag){
		  Sw2_Flag = 0;
		  /* txHeader 에 대한 구성 */
		  canTxHeader.StdId = 0x106;
		  canTxHeader.RTR = CAN_RTR_DATA;
		  canTxHeader.IDE = CAN_ID_STD;
		  canTxHeader.DLC = 8;

		  /** 데이터에 대한 정의 */
		  for(int i = 0; i < 8; ++i){
			  can1Tx0Data[i] ++;
		  }
		  /** 전송을 할 수 있는지 확인 */
		  TxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan1);
		  /** data 전송 */
		  HAL_CAN_AddTxMessage(&hcan1, &canTxHeader, &can1Tx0Data[0], &TxMailBox);

	  }
	  if(Sw3_Flag){
		  Sw3_Flag = 0;
		  /* txHeader 에 대한 구성 */
		  canTxHeader.StdId = 0x10A;
		  canTxHeader.RTR = CAN_RTR_DATA;
		  canTxHeader.IDE = CAN_ID_STD;
		  canTxHeader.DLC = 8;

		  /** 데이터에 대한 정의 */
		  for(int i = 0; i < 8; ++i){
			  can1Tx0Data[i] ++;
		  }
		  /** 전송을 할 수 있는지 확인 */
		  TxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan1);
		  /** data 전송 */
		  HAL_CAN_AddTxMessage(&hcan1, &canTxHeader, &can1Tx0Data[0], &TxMailBox);

	  }
	  if(Sw4_Flag){
		  Sw4_Flag = 0;
		  /* txHeader 에 대한 구성 */
		  canTxHeader.StdId = 0x10E;
		  canTxHeader.RTR = CAN_RTR_DATA;
		  canTxHeader.IDE = CAN_ID_STD;
		  canTxHeader.DLC = 8;

		  /** 데이터에 대한 정의 */
		  for(int i = 0; i < 8; ++i){
			  can1Tx0Data[i] ++;
		  }
		  /** 전송을 할 수 있는지 확인 */
		  TxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan1);
		  /** data 전송 */
		  HAL_CAN_AddTxMessage(&hcan1, &canTxHeader, &can1Tx0Data[0], &TxMailBox);

	  }
  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* USART3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* TIM7_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(TIM7_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM7_IRQn);
}

/* USER CODE BEGIN 4 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *hUart){
	if(hUart->Instance == USART3){
		HAL_UART_Receive_IT(&huart3, &rx_data, 1);
		HAL_UART_Transmit(&huart3, (const uint8_t*)&rx_data, 1, 10);
	}
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *hTim){
	static unsigned char cnt = 0;
	if(hTim->Instance == TIM7){
//		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
//		_7SEG_SetNumber(DGT1, cnt/10, OFF);
//		_7SEG_SetNumber(DGT2, cnt%10, ON);

		/** 최대로 높일 수는ㅇ벗고 나눈 값에 대한 절반 까지를 올릴 수 있다. */
//		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R,  (sinf(2*3.1415926533f * 50 * cnt /1000.f) + 1 ) * 2047);

		cnt++;
		if(cnt > 999)
		{
			cnt = 0;
		}
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == GPIO_PIN_3){
		Sw1_Flag = 1;
	}
	if(GPIO_Pin == GPIO_PIN_15){
		Sw2_Flag = 1;
	}
	if(GPIO_Pin == GPIO_PIN_4){
		Sw3_Flag = 1;
	}
	if(GPIO_Pin == GPIO_PIN_10){
		Sw4_Flag = 1;
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
