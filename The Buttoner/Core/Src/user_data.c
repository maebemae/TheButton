/*
 * user_data.c
 *
 *  Created on: Dec 30, 2024
 *      Author: mae
 */

#include "user_data.h"

#define MEMORY_DWORDS 1
//#define MEMORY_BANK_1 0x8010000  //unused
#define MEMORY_BANK_2 0x801F800

// This actually accesses data from the flash
// flash operates on dwords, so might as wel
const volatile uint64_t *userConfig = (const volatile uint64_t*) MEMORY_BANK_2;

uint64_t FLASH_Get_DWord(uint8_t offset) {
	if (offset > MEMORY_DWORDS - 1) {
		return 0;
	}
	return userConfig[offset];
}

// todo hacky solution, just allows writing a single dword and deletes the whole page
Flash_Status_TypeDef FLASH_Write_DWord(uint8_t offset, uint64_t data) {

	if (offset > MEMORY_DWORDS - 1) {
		return INVALID_OFFSET;
	}
	if (HAL_FLASH_Unlock() != HAL_OK) {
		Error_Handler();
		return LOCK_UNLOCK_ERROR;
	}


	// erase flash bank 1
	FLASH_EraseInitTypeDef eraseTypeDef;
	eraseTypeDef.NbPages = 1;
	eraseTypeDef.Page = 63;
	eraseTypeDef.TypeErase = FLASH_TYPEERASE_PAGES;
	uint32_t pageError;
	HAL_FLASHEx_Erase(&eraseTypeDef, &pageError);
	if (pageError != 0xFFFFFFFF) {
		// or should we lock this?
		return ERASE_ERROR;

	}
	uint8_t result = HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD,
	MEMORY_BANK_2 + offset * 8, data);

	if(result != HAL_OK){
		return WRITE_ERROR;
	}


	if (HAL_FLASH_Lock() != HAL_OK) {
		Error_Handler();
		return LOCK_UNLOCK_ERROR;
	}

	return OK;

}
