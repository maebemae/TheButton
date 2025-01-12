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

#define MSG_STATUS_BIT_OK 0
#define MSG_STATUS_BIT_VALID_CRC 1

#define MSG_STATUS_MASK_OK 		  1 << MSG_STATUS_BIT_OK
#define MSG_STATUS_MASK_VALID_CRC 1 << MSG_STATUS_BIT_VALID_CRC

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
	uint8_t crc;
} Button_Messages;


Button_Messages* messages_get_current();

static_assert(sizeof(Button_Messages) <= 2048, "Button_Message exceeds Flash Page Size page size");

#endif /* INC_MESSAGES_H_ */
