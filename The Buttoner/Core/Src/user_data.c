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
const volatile Button_Messages *userConfig =
		(const volatile Button_Messages*) MEMORY_BANK_2;

Button_Messages* FLASH_get_user_messages() {
	return userConfig;
}


Flash_Status_TypeDef erase_user_config() {
	FLASH_EraseInitTypeDef eraseTypeDef;
	eraseTypeDef.NbPages = 1;
	eraseTypeDef.Page = 63;
	eraseTypeDef.TypeErase = FLASH_TYPEERASE_PAGES;
	uint32_t pageError;
	HAL_FLASHEx_Erase(&eraseTypeDef, &pageError);
	if (pageError != 0xFFFFFFFF) {
		return FLASH_ERASE_ERROR;
	}
	return FLASH_OK;
}

bool FLASH_write_user_messages(Button_Messages* messages){
	FLASH_print_update("--- DO NOT DISCONNECT POWER - THIS WILL LEAD TO DATA LOSS ---\r\n");
	if(HAL_FLASH_Unlock() != HAL_OK) {
		// handle can't unlock
		FLASH_print_update("Can't unlock flash!\r\n");
		return false;
	}

	FLASH_print_update("Erasing current messages from flash\r\n");
	if(erase_user_config() != FLASH_OK) {
		// handle can't
		FLASH_print_update("Failed to erase flash!\r\n");
	}

	FLASH_print_update("Erase successful, writing data\r\n");
	uint16_t total_size = sizeof(Button_Messages);

	uint64_t* data_double_word = (uint64_t *)messages;

	for(uint16_t offset = 0; offset < total_size; offset+=8) {
		if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, MEMORY_BANK_2 + offset, *data_double_word++) != HAL_OK)
		{
			FLASH_print_update("Failed to write to flash!\r\n");
			return false;
		}

	}

	if(HAL_FLASH_Lock() != HAL_OK) {
		FLASH_print_update("Failed to lock flash after operation!\r\n");
		return false;
	}
	FLASH_print_update("Write successful!\r\n");
	FLASH_print_update("--- It is now safe to disconnect power ---\r\n");
	return true;
}

