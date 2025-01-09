/*
 * bootloader.h
 *
 *  Created on: Jan 2, 2025
 *      Author: mae
 */

#ifndef INC_BOOTLOADER_H_
#define INC_BOOTLOADER_H_


// copied from https://community.st.com/t5/stm32-mcus/how-to-jump-to-system-bootloader-from-application-code-on-stm32/ta-p/49424
enum{C0, F030x8, F030xC, F03xx, F05, F07, F09, F10xx, F105, F107, F10XL, F2, F3, F4, F7, G0, G4, H503, H563, H573, H7x, H7A, H7B, L0, L1, L4, L5, WBA, WBX, WL, U5};

#define MCU			C0		//Define here the MCU being used

void JumpToBootloader(void);

#endif /* INC_BOOTLOADER_H_ */
