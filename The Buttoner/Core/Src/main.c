/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

__IO uint32_t BspButtonState = BUTTON_RELEASED;

TIM_HandleTypeDef htim2;

PCD_HandleTypeDef hpcd_USB_DRD_FS;

/* USER CODE BEGIN PV */
// the funny character is not interpreted, so it acts as a pause while printing
//const char NSFW_TEXTS[][100] = {{"FUUUUCK!\n"}, {"FUCK!\n"}, {"Fuck.\n"}, {"Uhhššš fuck?\n"}};
const char NSFW_TEXTS[][100] = {{"AUGGHHHHHH!!! (>_<)\n"}, {"UGH! >.<\n"}, {"ugh... -_-\n"}, {"uhhššš ugh? ._.\n"}};

const char SFW_TEXTS[][100] = {{"My enemies have succeeded!\n"}, {"It is impossible to underestimate you...\n"}, {"Another great day to generate shareholder value\n"}, {"I'm afraid that,...šš I am currently unable to can\n"}};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USB_PCD_Init(void);
static void MX_TIM2_Init(void);
static void MX_FLASH_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void start_button_timer() {
	htim2.Instance->CNT = 0; // initial run timers seems to be running alr
	HAL_TIM_Base_Start_IT(&htim2);
}

bool enable_nsfw(){

	return (HAL_GPIO_ReadPin(KEY_SWITCH_GPIO_Port, KEY_SWITCH_Pin) == 0);
}

void print_message(uint32_t pressDurationUs) {
	uint8_t severity;
	if (pressDurationUs < HARD_MED_LIMIT_US) {
		severity = 0;
	} else if (pressDurationUs < MED_SOFT_LIMIT_US) {
		severity = 1;
	} else if (pressDurationUs < SOFT_LIMIT_US) {
		severity = 2;
	} else {
		severity = 3;
	}

//	uint8_t selection = pressDurationUs %

	if(enable_nsfw())
	{
		hid_print_text(&NSFW_TEXTS[severity][0]);
	} else {
		hid_print_text(&SFW_TEXTS[severity][0]);
	}

}

void end_button_timer() {
	if (htim2.Instance->CNT > 0) {
		uint32_t currentCount = htim2.Instance->CNT;
		HAL_TIM_Base_Stop_IT(&htim2);
		uint32_t durationUs = currentCount / 12;
//		hid_write_number(currentCount / 12;
		print_message(durationUs );

		htim2.Instance->CNT = 0; // clear the counter so we can't double trigger
	}
}

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == BUTTON_LO_Pin) {
		BSP_LED_Off(LED_GREEN);
	}
	if (GPIO_Pin == BUTTON_HI_Pin) {
		BSP_LED_Off(LED_BLUE);
		HAL_GPIO_WritePin(USR_LED2_GPIO_Port, USR_LED2_Pin, GPIO_PIN_RESET);
	}
	if (GPIO_Pin == KEY_SWITCH_Pin) {
		  GPIO_InitTypeDef GPIO_InitStruct = {0};
		  GPIO_InitStruct.Pin = KEY_SWITCH_LED_Pin;
		  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
		  GPIO_InitStruct.Pull = GPIO_PULLDOWN; // cheating by using internal resistor instead of push/pull -> LED OFF
		  HAL_GPIO_Init(KEY_SWITCH_LED_GPIO_Port, &GPIO_InitStruct);
	}

}

void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == BUTTON_LO_Pin) {
		BSP_LED_On(LED_GREEN);
		end_button_timer();
	}
	if (GPIO_Pin == BUTTON_HI_Pin) {
		BSP_LED_On(LED_BLUE);
		HAL_GPIO_WritePin(USR_LED2_GPIO_Port, USR_LED2_Pin, GPIO_PIN_SET);
		start_button_timer();
	}
	if (GPIO_Pin == KEY_SWITCH_Pin) {
		  GPIO_InitTypeDef GPIO_InitStruct = {0};
		  GPIO_InitStruct.Pin = KEY_SWITCH_LED_Pin;
		  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
		  GPIO_InitStruct.Pull = GPIO_PULLUP; // cheating by using internal resistor instead of push/pull
		  HAL_GPIO_Init(KEY_SWITCH_LED_GPIO_Port, &GPIO_InitStruct);
	}
}

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
  MX_USB_PCD_Init();
  MX_TIM2_Init();
  MX_FLASH_Init();
  /* USER CODE BEGIN 2 */

  if((HAL_GPIO_ReadPin(BUTTON_HI_GPIO_Port, BUTTON_HI_Pin) == 0 && HAL_GPIO_ReadPin(BUTTON_LO_GPIO_Port, BUTTON_LO_Pin) == 0)){
	  // enter bootloader
	  JumpToBootloader();
  }


  /* USER CODE END 2 */

  /* Initialize leds */
  BSP_LED_Init(LED_GREEN);
  BSP_LED_Init(LED_BLUE);

  /* Initialize USER push-button, will be used to trigger an interrupt each time it's pressed.*/
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);

  /* USER CODE BEGIN BSP */

	/* -- Sample board code to switch on leds ---- */

	USBapp_Init();

  /* USER CODE END BSP */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
		// just wait for interrupts
		__WFI();

//    /* -- Sample board code for User push-button in interrupt mode ---- */
//    if (BspButtonState == BUTTON_PRESSED)
//    {
//      /* Update button state */
//      BspButtonState = BUTTON_RELEASED;
//      /* -- Sample board code to toggle leds ---- */
//      BSP_LED_Toggle(LED_GREEN);
//      BSP_LED_Toggle(LED_BLUE);
//
//      /* ..... Perform your action ..... */
//    }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_0);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV4;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief FLASH Initialization Function
  * @param None
  * @retval None
  */
static void MX_FLASH_Init(void)
{

  /* USER CODE BEGIN FLASH_Init 0 */

  /* USER CODE END FLASH_Init 0 */

  FLASH_OBProgramInitTypeDef pOBInit = {0};

  /* USER CODE BEGIN FLASH_Init 1 */

  /* USER CODE END FLASH_Init 1 */
  if (HAL_FLASH_Unlock() != HAL_OK)
  {
    Error_Handler();
  }

  /* Option Bytes settings */

  if (HAL_FLASH_OB_Unlock() != HAL_OK)
  {
    Error_Handler();
  }
  pOBInit.OptionType = OPTIONBYTE_USER;
  pOBInit.USERType = OB_USER_NBOOT_SEL;
  pOBInit.USERConfig = OB_BOOT0_FROM_PIN;
  if (HAL_FLASHEx_OBProgram(&pOBInit) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_FLASH_OB_Lock() != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_FLASH_Lock() != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FLASH_Init 2 */
  /* USER CODE END FLASH_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_ENABLE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */
	HAL_TIM_Base_Start(&htim2);
  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USB Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_PCD_Init(void)
{

  /* USER CODE BEGIN USB_Init 0 */

  /* USER CODE END USB_Init 0 */

  /* USER CODE BEGIN USB_Init 1 */

  /* USER CODE END USB_Init 1 */
  hpcd_USB_DRD_FS.Instance = USB_DRD_FS;
  hpcd_USB_DRD_FS.Init.dev_endpoints = 8;
  hpcd_USB_DRD_FS.Init.speed = USBD_FS_SPEED;
  hpcd_USB_DRD_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
  hpcd_USB_DRD_FS.Init.Sof_enable = DISABLE;
  hpcd_USB_DRD_FS.Init.low_power_enable = DISABLE;
  hpcd_USB_DRD_FS.Init.lpm_enable = DISABLE;
  hpcd_USB_DRD_FS.Init.battery_charging_enable = DISABLE;
  hpcd_USB_DRD_FS.Init.vbus_sensing_enable = DISABLE;
  hpcd_USB_DRD_FS.Init.bulk_doublebuffer_enable = DISABLE;
  hpcd_USB_DRD_FS.Init.iso_singlebuffer_enable = DISABLE;
  if (HAL_PCD_Init(&hpcd_USB_DRD_FS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_Init 2 */

  /* USER CODE END USB_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USR_LED2_GPIO_Port, USR_LED2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : KEY_SWITCH_LED_Pin */
  GPIO_InitStruct.Pin = KEY_SWITCH_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY_SWITCH_LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USR_LED2_Pin */
  GPIO_InitStruct.Pin = USR_LED2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USR_LED2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : KEY_SWITCH_Pin BUTTON_LO_Pin BUTTON_HI_Pin */
  GPIO_InitStruct.Pin = KEY_SWITCH_Pin|BUTTON_LO_Pin|BUTTON_HI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  BSP Push Button callback
  * @param  Button Specifies the pressed button
  * @retval None
  */
void BSP_PB_Callback(Button_TypeDef Button)
{
  if (Button == BUTTON_USER)
  {
    BspButtonState = BUTTON_PRESSED;
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
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
