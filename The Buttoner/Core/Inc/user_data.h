/*
 * user_data.h
 *
 *  Created on: Dec 30, 2024
 *      Author: mae
 */

#ifndef INC_USER_DATA_H_
#define INC_USER_DATA_H_

#include <stdint.h>
#include "stm32c0xx_hal.h"

#include "messages.h"

typedef enum
{
  FLASH_OK       = 0x00U,
  FLASH_INVALID_OFFSET = 0x01U,
  FLASH_WRITE_ERROR    = 0x02U,
  FLASH_LOCK_UNLOCK_ERROR = 0x03U,
  FLASH_ERASE_ERROR = 0x04

} Flash_Status_TypeDef;



void FLASH_get_user_data(uint64_t* target, uint16_t len);
bool FLASH_write_user_messages(uint64_t* messages);

// override to have a printout of what's happening
__weak void FLASH_print_update(char* message) {}




#endif /* INC_USER_DATA_H_ */
