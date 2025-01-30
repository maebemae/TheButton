/*
 * messages.h
 *
 *  Created on: Jan 12, 2025
 *      Author: mae
 */

#ifndef INC_MESSAGES_H_
#define INC_MESSAGES_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "user_data.h"

// arbitrary pattern which will not match if flash is cleared to 0xFFFF, or typedef is initialized to 0x0000
#define MSG_STATUS_VALID 0b01101010


#define MAX_MESSAGE_LEN 255

#ifndef MAX_MESSAGE_LEN
	#error "MAX_MESSAGE_LEN must be defined"
#endif
#if MAX_MESSAGE_LEN > 255
	#error "max message length is 255"
#endif

typedef struct Button_Messages {
	uint8_t status;
	uint8_t bank_a[4][MAX_MESSAGE_LEN];
	uint8_t bank_b[4][MAX_MESSAGE_LEN];
	uint8_t checksum;
} Button_Messages;


Button_Messages* messages_get_current();
Button_Messages* messages_get_default();


static_assert(sizeof(Button_Messages) <= 2048, "Button_Message exceeds Flash Page Size page size");

#endif /* INC_MESSAGES_H_ */
