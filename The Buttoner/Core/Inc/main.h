/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32c0xx_hal.h"
#include "stm32c0xx_nucleo.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usb_app.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY_SWITCH_Pin GPIO_PIN_7
#define KEY_SWITCH_GPIO_Port GPIOA
#define BUTTON_LO_Pin GPIO_PIN_8
#define BUTTON_LO_GPIO_Port GPIOA
#define BUTTON_LO_EXTI_IRQn EXTI4_15_IRQn
#define BUTTON_HI_Pin GPIO_PIN_9
#define BUTTON_HI_GPIO_Port GPIOA
#define BUTTON_HI_EXTI_IRQn EXTI4_15_IRQn


/* USER CODE BEGIN Private defines */

#define HARD_MED_LIMIT_US 5000
#define MED_SOFT_LIMIT_US 30000
#define SOFT_LIMIT_US 100000

#define HARD_TEXT "FUUUUCK!"
#define MED_TEXT "FUCK!"
#define SOFT_TEXT "Fuck."
#define ULTRA_SOFT_TEXT "Uhh fuck?"

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
