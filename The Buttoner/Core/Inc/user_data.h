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

typedef enum
{
  OK       = 0x00U,
  INVALID_OFFSET = 0x01U,
  WRITE_ERROR    = 0x02U,
  LOCK_UNLOCK_ERROR = 0x03U,
  ERASE_ERROR = 0x04

} Flash_Status_TypeDef;

uint64_t FLASH_Get_DWord(uint8_t offset);
Flash_Status_TypeDef FLASH_Write_DWord(uint8_t offset, uint64_t data);


#endif /* INC_USER_DATA_H_ */
