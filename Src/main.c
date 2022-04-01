/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"
#include "calculator.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "kb.h"
#include "sdk_uart.h"
#include "pca9538.h"
#include "oled.h"
#include "fonts.h"

#include <stdlib.h>
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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void KB_Test(void);
void OLED_KB(uint8_t OLED_Keys[]);
void oled_Reset(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
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
	MX_I2C1_Init();
	MX_USART6_UART_Init();
	/* USER CODE BEGIN 2 */
	oled_Init();

	oled_Reset();
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
		run();
//		oled_Reset();
//		oled_WriteString("Hi", Font_11x18, White);
//		oled_UpdateScreen();
//
//		int64_t a = 0, b = 0, lenA = 0, lenB = 0;
//		uint8_t Row[4] = { 0xF7, 0x7B, 0x3D, 0x1E }, Key, mode = 0, operation =
//				-1;
//		int8_t newNumber = -3;
//		char charsFromA[18];
//
//		while (1) {
//			for (int i = 0; i < 4; i++) {
//				Key = Check_Row(Row[i]);
//				switch (i) {
//				case 0:
//					switch (Key) {
//					case 0x01:
//						newNumber = -2;
//						break;
//
//					case 0x02:
//						newNumber = -1;
//						break;
//
//					case 0x04:
//						newNumber = 0;
//						break;
//					}
//					break;
//
//				case 1:
//					switch (Key) {
//					case 0x01:
//						newNumber = 3;
//						break;
//
//					case 0x02:
//						newNumber = 2;
//						break;
//
//					case 0x04:
//						newNumber = 1;
//						break;
//					}
//					break;
//
//				case 2:
//					switch (Key) {
//					case 0x01:
//						newNumber = 6;
//						break;
//
//					case 0x02:
//						newNumber = 5;
//						break;
//
//					case 0x04:
//						newNumber = 4;
//						break;
//					}
//					break;
//
//				case 3:
//					switch (Key) {
//					case 0x01:
//						newNumber = 9;
//						break;
//
//					case 0x02:
//						newNumber = 8;
//						break;
//
//					case 0x04:
//						newNumber = 7;
//						break;
//					}
//					break;
//
//				}
//
//				if (Key != 0x0) {
//					switch (mode) {
//					case 0: // режим первый - ввод числа
//						switch (newNumber) {
//						case -1:
//							if (lenA != 0) { // TODO должно быть поведение если длина нулевая
//								mode = 1;
//								oled_SetCursor(0, 10);
//							}
//							break;
//						case -2:
//							if (lenA != 0) { // унарный минус
//								oled_SetCursor(0, 0); // идем в начало числа
//								a *= -1;
//								if (a < 0) {
//									oled_WriteChar('-', Font_7x10, White);
//								} else if (a > 0) {
//									oled_WriteChar(' ', Font_7x10, White);
//								}
//								oled_SetCursor(7 * (lenA + 1), 0); // возвращаемся в конец числа
//							}
//							break;
//
//						default:
//							if (lenA == 0) {
//								oled_Reset();
//								oled_WriteChar(' ', Font_7x10, White);
//								oled_WriteChar(newNumber + '0', Font_7x10, // перевод числа в char
//										White);
//								a = newNumber;
//								lenA++;
//							} else if (a != 0 && lenA < 16) {
//								a *= 10;
//								a += newNumber;
//								oled_WriteChar(newNumber + '0', Font_7x10,
//										White);
//								lenA++;
//							} // TODO логика если ввели  а потом другую цифру + кога переполнилсоь
//							break;
//						}
//						break;
//
//					case 1: // режим второй - ввод операции
//						switch (newNumber) {
//						case 7: // TODO не делаем режими когда разные кнопки делают разное
//							operation = 0; // ENUM
//							oled_WriteChar('+', Font_7x10, White);
//							oled_SetCursor(0, 20);
//							mode = 2;
//							break;
//						case 8:
//							operation = 1;
//							oled_WriteChar('-', Font_7x10, White);
//							oled_SetCursor(0, 20);
//							mode = 2;
//							break;
//						case 9:
//							operation = 2;
//							oled_WriteChar('*', Font_7x10, White);
//							oled_SetCursor(0, 20);
//							mode = 2;
//							break;
//						}
//						break;
//
//					case 2: // третий режим - считываем второе число
//						switch (newNumber) {
//						case -1: // Здесь -1 это равно
//							if (lenB != 0) {
//								switch (operation) {
//								case 0:
//									a += b;
//									break;
//								case 1:
//									a -= b;
//									break;
//								case 2:
//									a *= b;
//									break;
//								}
//								b = 0;
//								lenB = 0;
//								oled_Reset();
//								itoa(a, charsFromA, 10);
//								if (a >= 0) oled_WriteChar(' ', Font_7x10, White);
//								oled_WriteString(charsFromA, Font_7x10, White);
//
//								mode = 1;
//								oled_SetCursor(0, 10); // вернулись в режим выбора операции и перешли на вторую строку
//							}
//							break;
//						case -2: // унарный минус для второго числа
//							if (lenB != 0) {
//								oled_SetCursor(0, 20);
//								b *= -1;
//								if (b < 0) {
//									oled_WriteChar('-', Font_7x10, White);
//								} else if (b > 0) {
//									oled_WriteChar(' ', Font_7x10, White);
//								}
//								oled_SetCursor(7 * (lenB + 1), 20);
//							}
//							break;
//						default:
//							if (lenB == 0) {
//								oled_WriteChar(' ', Font_7x10, White);
//								oled_WriteChar(newNumber + '0', Font_7x10,
//										White);
//								b = newNumber;
//								lenB++;
//							} else if (b != 0 && lenB < 16) {
//								b *= 10;
//								b += newNumber;
//								oled_WriteChar(newNumber + '0', Font_7x10,
//										White);
//								lenB++;
//							}
//							break;
//						}
//						break;
//					}
//					oled_UpdateScreen();
//				}
//			}
//			HAL_Delay(500); // защита от дребезга
//		}
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 4;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */

void oled_Reset(void) {
	oled_Fill(Black);
	oled_SetCursor(0, 0);
	oled_UpdateScreen();
}

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
