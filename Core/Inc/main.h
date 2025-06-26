/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define btnE_Pin GPIO_PIN_0
#define btnE_GPIO_Port GPIOF
#define btnQ_Pin GPIO_PIN_1
#define btnQ_GPIO_Port GPIOF
#define btnTab_Pin GPIO_PIN_2
#define btnTab_GPIO_Port GPIOF
#define btnZ_Pin GPIO_PIN_3
#define btnZ_GPIO_Port GPIOF
#define btn1_Pin GPIO_PIN_4
#define btn1_GPIO_Port GPIOF
#define btn2_Pin GPIO_PIN_5
#define btn2_GPIO_Port GPIOF
#define btn3_Pin GPIO_PIN_6
#define btn3_GPIO_Port GPIOF
#define btn4_Pin GPIO_PIN_7
#define btn4_GPIO_Port GPIOF
#define btnSpace_Pin GPIO_PIN_8
#define btnSpace_GPIO_Port GPIOF
#define btnX_Pin GPIO_PIN_9
#define btnX_GPIO_Port GPIOF
#define leftMouse_Pin GPIO_PIN_10
#define leftMouse_GPIO_Port GPIOF
#define modifier_Pin GPIO_PIN_0
#define modifier_GPIO_Port GPIOA
#define rightMouse_Pin GPIO_PIN_11
#define rightMouse_GPIO_Port GPIOF
#define btnL_Pin GPIO_PIN_12
#define btnL_GPIO_Port GPIOF
#define btnEsc_Pin GPIO_PIN_13
#define btnEsc_GPIO_Port GPIOF

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
