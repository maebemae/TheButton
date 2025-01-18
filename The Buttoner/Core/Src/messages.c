/*
 * messages.c
 *
 *  Created on: Jan 12, 2025
 *      Author: mae
 */

#include "messages.h"

bool initialized = false;

const Button_Messages default_messages = {
		.status = MSG_STATUS_VALID,
		.bank_a = {"FUUUUCK!!\n", "FUCK!\n", "Fuck.\n", "Uhhššš fuck?\n"},
		.bank_b = {"My enemies have succeeded!\n", "It is impossible to underestimate you...\n", "Another great day to generate shareholder value\n", "I'm afraid that...šš I am currently unable to can\n"}
};

Button_Messages current_messages;

// hurm probably better ways of doing this
Button_Messages* messages_get_default(){
	return &default_messages;
}

bool valid(Button_Messages* messages) {

	// todo actually implement the crc check
	return messages->status == MSG_STATUS_VALID;
}

Button_Messages* messages_get_current(){
	if(!initialized){
		FLASH_get_user_data((uint64_t*) &current_messages, sizeof(Button_Messages));
		initialized = true;
	}
	if(!valid(&current_messages)){
		 memcpy(&current_messages, &default_messages, sizeof(Button_Messages));
	}
	 return &current_messages;

}




