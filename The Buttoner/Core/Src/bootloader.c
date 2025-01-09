/*
 * bootloader.c
 *
 *  Created on: Jan 2, 2025
 *      Author: mae
 */


#include "bootloader.h"
// This is bleble, but for now just workig with c0s
#include "stm32c0xx_hal.h"

#include <stdint.h>


void JumpToBootloader (void)
{
	uint32_t i=0;
	void (*SysMemBootJump)(void);


/* Set a vector addressed with STM32 Microcontrollers names */
/* Each vector position contains an address to the boot loader entry point */

	volatile uint32_t BootAddr[33];

	BootAddr[C0]     = 0x1FFF0000;
	BootAddr[F030x8] = 0x1FFFEC00;
	BootAddr[F030xC] = 0x1FFFD800;
	BootAddr[F03xx]  = 0x1FFFEC00;
	BootAddr[F05]    = 0x1FFFEC00;
	BootAddr[F07]    = 0x1FFFC800;
	BootAddr[F09]    = 0x1FFFD800;
	BootAddr[F10xx]  = 0x1FFFF000;
	BootAddr[F105]   = 0x1FFFB000;
	BootAddr[F107]   = 0x1FFFB000;
	BootAddr[F10XL]  = 0x1FFFE000;
	BootAddr[F2]     = 0x1FFF0000;
	BootAddr[F3]     = 0x1FFFD800;
	BootAddr[F4]     = 0x1FFF0000;
	BootAddr[F7]     = 0x1FF00000;
	BootAddr[G0]     = 0x1FFF0000;
	BootAddr[G4]     = 0x1FFF0000;
	BootAddr[H503]   = 0x0BF87000;
	BootAddr[H563]   = 0x0BF97000;
	BootAddr[H573]   = 0x0BF97000;
	BootAddr[H7x]    = 0x1FF09800;
	BootAddr[H7A]    = 0x1FF0A800;
	BootAddr[H7B]    = 0x1FF0A000;
	BootAddr[L0]     = 0x1FF00000;
	BootAddr[L1]     = 0x1FF00000;
	BootAddr[L4]     = 0x1FFF0000;
	BootAddr[L5]     = 0x0BF90000;
	BootAddr[WBA]    = 0x0BF88000;
	BootAddr[WBX]    = 0x1FFF0000;
	BootAddr[WL]     = 0x1FFF0000;
	BootAddr[U5]     = 0x0BF90000;

	/* Disable all interrupts */
	__disable_irq();

	/* Disable Systick timer */
	SysTick->CTRL = 0;

	/* Set the clock to the default state */
	HAL_RCC_DeInit();

	/* Clear Interrupt Enable Register & Interrupt Pending Register */
	for (i=0;i<5;i++)
	{
		NVIC->ICER[i]=0xFFFFFFFF;
		NVIC->ICPR[i]=0xFFFFFFFF;
	}

	/* Re-enable all interrupts */
	__enable_irq();

	/* Set up the jump to boot loader address + 4 */
	SysMemBootJump = (void (*)(void)) (*((uint32_t *) ((BootAddr[MCU] + 4))));

	/* Set the main stack pointer to the boot loader stack */
	__set_MSP(*(uint32_t *)BootAddr[MCU]);

	/* Call the function to jump to boot loader location */
	SysMemBootJump();

	/* Jump is done successfully */
	while (1)
	{
		/* Code should never reach this loop */
	}
}

