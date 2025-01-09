/*
 * lightweight USB device stack by gbm
 * mcu_hw.h - STM32U0-specific setup routines for USB
 * Copyright (c) 2024 gbm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INC_MCU_HW_H_
#define INC_MCU_HW_H_

#include <stdbool.h>
#include "stm32u0yy.h"
#include "bf_reg.h"		// from github.com/gbm-ii/STM32_Inc
#include "boards/stm32u083c-dk.h"

/*
 * The routines below are supposed to be called only once, so they are defined as static inline
 * in a header file.
 */

// minimal clock setup required for USB device operation
static inline void ClockSetup(void)
{
	// set HCLK to 56 MHz PLL fed by MSI, use HSI48 synchronized to SOF for USB
	// PWR Range 1 is the default - ok for 56 MHz
	RCC->APBENR1 |= RCC_APBENR1_PWREN | RCC_APBENR1_CRSEN;

	// PLL M = 1, N = 28, R = 2 for 56 MHz HCLK
	RCC->PLLCFGR = RCC_PLLCFGR_PLLNV(28) | RCC_PLLCFGR_PLLRV(2) | RCC_PLLCFGR_PLLMV(1) | RCC_PLLCFGR_PLLREN | RCC_PLLCFGR_PLLSRC_0;	// MSI
	RCC->CRRCR |= RCC_CRRCR_HSI48ON;
	RCC->CR |= RCC_CR_PLLON;
	FLASH->ACR |= FLASH_ACR_PRFTEN | 2u << FLASH_ACR_LATENCY_Pos; // 2 WS up to 56 MHz
    RCC->APBENR1 |= RCC_APBENR1_CRSEN;
    CRS->CR |= CRS_CR_AUTOTRIMEN | CRS_CR_CEN;	// sync HSI48 to USB SOF

	while (~RCC->CRRCR & RCC_CRRCR_HSI48RDY) ;
	RCC->CCIPR = RCC_CCIPR_CLK48SEL_Msk;	// select HSI48 as USB clock
	while (~RCC->CR & RCC_CR_PLLRDY) ;
	RCC->CFGR = RCC_CFGR_SW_PLLRCLK;
}

// USB peripheral enable & pin configuration
static inline void USBhwSetup(void)
{
    RCC->APBENR1 |= RCC_APBENR1_PWREN;
	PWR->CR2 |= PWR_CR2_USV; // | PWR_CR2_PVME1;
    RCC->APBENR1 |= RCC_APBENR1_USBEN;
	// With G0 and U0 series, MODER and OSPEEEDR value is "don't care" for USB data pins
}

// board LED/Button setup needed for HID demo
static inline void LED_Btn_Setup(void)
{
#ifdef LED_PORT
	RCC->IOENR |= RCC_IOENR_GPIOEN(LED_PORT);
	BF2F(LED_PORT->MODER, LED_BIT) = GPIO_MODER_OUT;
#endif
#ifdef BTN_PORT
	RCC->IOENR |= RCC_IOENR_GPIOEN(BTN_PORT);
	BF2F(BTN_PORT->PUPDR, BTN_BIT) = GPIO_PUPDR_PD;
	BF2F(BTN_PORT->MODER, BTN_BIT) = GPIO_MODER_IN;
#endif
}

static inline void hwLED_Set(bool on)
{
#ifdef LED_PORT
	LED_PORT->BSRR = on ? LED_MSK : LED_MSK << 16;
#endif
}

#endif /* INC_MCU_HW_H_ */
