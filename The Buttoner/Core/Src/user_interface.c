/*
 * user_interface.c
 *
 *  Created on: Jan 11, 2025
 *      Author: mae
 */

#include "user_interface.h"

typedef enum Current_MenuTypedef {
	MENU_MAIN,
	MENU_CHOOSE_MESSAGE_TO_EDIT,
	MENU_EDITING_MESSAGE,
	MENU_RESTORE_FACTORY,
} Current_MenuTypedef;

Current_MenuTypedef current_menu = MENU_MAIN;

char message[MAX_MESSAGE_LEN];
uint16_t currentChar = 0;

char selectedBank;
uint8_t selectedMessage;

char message_buffer[100];

void print_current_messages(uint8_t ch) {
	vcom_putstring(ch, "\r\nNSFW Messages:\r\n");
	for (uint8_t i = 0; i < 4; i++) {
		sprintf(message_buffer, "\t A%u: ", i);
		vcom_putstring(ch, message_buffer);
		vcom_putstring(ch, (const char*) messages_get_current()->bank_a[i]);

	}
	vcom_putstring(ch, "\r\nSFW Messages:\r\n");
	for (uint8_t i = 0; i < 4; i++) {
		sprintf(message_buffer, "\t B%u: ", i);
		vcom_putstring(ch, message_buffer);
		vcom_putstring(ch, (const char*) messages_get_current()->bank_b[i]);
	}
	vcom_putchar(ch, '\r');
	vcom_putchar(ch, '\n');
}

uint8_t handle_main_menu(uint8_t ch) {
	if (currentChar < 1) {
		vcom_putstring(ch, "Unknown Command, please try again\r\n");
		return 1;
	}

	char c = message[0];
	switch (c) {
	case '1':
		print_current_messages(ch);
		vcom_putstring(ch, SIGNON0);
		current_menu = MENU_MAIN;
		return 0;
	case '2':
		vcom_putstring(ch,
				"\r\nYour messages will be updated immediately for this session, but you will need to write them to flash to persist them.\r\n");
		print_current_messages(ch);
		vcom_putstring(ch,
				"\r\n\t0: Back to main menu\r\n\t1: Write changes to flash\r\n\t[message]: Edit the message, e.g. B2\r\n\r\n");
		current_menu = MENU_CHOOSE_MESSAGE_TO_EDIT;
		return 1;
	case '9':
		// restore factory settings
		current_menu = MENU_RESTORE_FACTORY;
		return 1;

	}

	sprintf(message_buffer, "[%s] -> Unknown command, please try again\r\n",
			c == '\n' ? "whitespace" : c);

	return 1;
}

void handle_choose_message(uint8_t ch) {
	if (message[0] == '0') {
		current_menu = MENU_MAIN;
		vcom_putstring(ch, SIGNON0);
		return;
	}
	if (message[0] == '1') {
		// write to flash
		if (!FLASH_write_user_messages((uint64_t*) messages_get_current())) {
			vcom_putstring(ch,
					"Failed to write the message to flash. You may retry, restore to defaults, power cycle the button\r\n\r\n");
		}
		current_menu = MENU_MAIN;
		vcom_putstring(ch, SIGNON0);
		return;
	}
	// editing a message
	char bank = message[0];
	if (bank == 'a' || bank == 'A') {
		selectedBank = 'A';
	} else if (bank == 'b' || bank == 'B') {
		selectedBank = 'B';
	} else {
		sprintf(message_buffer, "Unknown bank: %c\r\n", bank);
		vcom_putstring(ch, message_buffer);
		return;
	}

	uint8_t id = message[1] - '0';
	if (id < 4) {
		selectedMessage = id;
	} else {
		sprintf(message, "Unknown id: %u\r\n", id);
		vcom_putstring(ch, message);
		return;
	}
	vcom_putstring(ch, "\r\nPlease enter your new message:\r\n");
	current_menu = MENU_EDITING_MESSAGE;
}

void handle_edit_message(uint8_t ch) {
	if (selectedBank == 'A') {
		strcpy((char*) messages_get_current()->bank_a[selectedMessage],
				message);
	} else if (selectedBank == 'B') {
		strcpy((char*) messages_get_current()->bank_b[selectedMessage],
				message);
	} else {
		sprintf(message_buffer,
				"Attempted to write to unknown bank [%c], this should never happen!\r\n",
				selectedBank);
		vcom_putstring(ch, message_buffer);
	}
	vcom_putstring(ch, "Updated\r\n");
	message[0] = '2'; // navigate back to messages
	handle_main_menu(ch);

}

uint8_t handle_restore_factory(uint8_t ch) {
//	memcpy(messages_get_current(), messages_get_default(),
//			sizeof(Button_Messages));

	vcom_putstring(ch,
			"Loaded factory default messages, you can now edit them, or write to flash");
	message[0] = '2'; // navigate back to messages
	handle_main_menu(ch);
	return 0;
}

// callback for each character received from
uint8_t vcom_process_input(uint8_t ch, uint8_t c) {
	if (currentChar >= MAX_MESSAGE_LEN) {
		memset(&message, 0, MAX_MESSAGE_LEN);
		currentChar = 0;

		vcom_putstring(ch, MESSAGE_TOO_LONG);
		return 0;
	}
	message[currentChar++] = c;
	if (c != '\n') {
		// build up the message char by char
		return 1;
	}

	switch (current_menu) {
	case MENU_MAIN:
		handle_main_menu(ch);
		break;

	case MENU_CHOOSE_MESSAGE_TO_EDIT:
		handle_choose_message(ch);
		break;
	case MENU_EDITING_MESSAGE:
		handle_edit_message(ch);
		break;

	case MENU_RESTORE_FACTORY:
		handle_restore_factory(ch);
		break;
	default:
		vcom_putstring(ch,
				"Unexpected state, please unplug and plug The Button back in\r\n");
		break;
	}

	memset(&message, 0, MAX_MESSAGE_LEN);
	currentChar = 0;

	return 0; // 1 == prompt requested
}

