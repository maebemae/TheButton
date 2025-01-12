/*
 * messages.c
 *
 *  Created on: Jan 12, 2025
 *      Author: mae
 */

#include "messages.h"

bool initialized = false;

const Button_Messages default_messages = {
		.status = MSG_STATUS_MASK_OK,
		.bank_a = {"FUUUUCK!!\n", "FUCK!\n", "Fuck.\n", "Uhhššš fuck?\n"},
		.bank_b = {"My enemies have succeeded!\n", "It is impossible to underestimate you...\n", "Another great day to generate shareholder value\n", "I'm afraid that...šš I am currently unable to can\n"}
};

Button_Messages current_messages;

// hurm probably better ways of doing this
Button_Messages* messages_get_default(){
	return &default_messages;
}

Button_Messages* messages_get_current(){
	if(!initialized){
		FLASH_get_user_data((uint64_t*) &current_messages, sizeof(Button_Messages));
		initialized = true;
		FLASH_print_update("[DEBUG] Loaded user message from flash\r\n");
	}
	if(!current_messages.status & MSG_STATUS_MASK_OK){
		 memcpy(&current_messages, &default_messages, sizeof(Button_Messages));
		 FLASH_print_update("[DEBUG] user message invalid, loading factory\r\n");
	}
	 return &current_messages;

}



bool validCrc(Button_Messages* messages) {
	if(messages->status & MSG_STATUS_MASK_VALID_CRC) {
		return true; // todo actually implement the crc check
	} else {
		return true;
	}
}
