/*
 * user_interface.c
 *
 *  Created on: Jan 11, 2025
 *      Author: mae
 */


#include "user_interface.h"


typedef enum Current_MenuTypedef {
	MENU_MAIN,
	MENU_MESSAGES,
	MENU_RESTORE_FACTORY,
} Current_MenuTypedef;

Current_MenuTypedef current_menu = MENU_MAIN;

char message[MAX_MESSAGE_LEN];
uint16_t currentChar = 0;




void print_current_messages(uint8_t ch){
	vcom_putstring(ch, "NSFW Messages:\r\n");
	for(uint8_t i = 0; i < 4; i++){
		vcom_putchar(ch, '\t');
		vcom_putchar(ch, i + '0');
		vcom_putstring(ch, ": ");
		vcom_putstring(ch, (const char*)messages_get_default()->bank_a[i]);
		vcom_putchar(ch, '\r');
		vcom_putchar(ch, '\n');
	}
	vcom_putstring(ch, "SFW Messages:\r\n");
	for(uint8_t i = 0; i < 4; i++){
		vcom_putchar(ch, '\t');
		vcom_putchar(ch, i + '0');
		vcom_putstring(ch, ": ");
		vcom_putstring(ch, (const char*)messages_get_default()->bank_b[i]);
		vcom_putchar(ch, '\r');
		vcom_putchar(ch, '\n');
	}
}
void print_severity_prompt(uint8_t ch){
	FLASH_write_user_messages(messages_get_default());
}

uint8_t handle_main_menu(uint8_t ch) {
	if(currentChar < 1) {
		vcom_putstring(ch, "Unknown Command, please try again\r\n");
		return 1;
	}

	char c = message[0];
	switch(c) {
	case '1':
		print_current_messages(ch);
		current_menu = MENU_MAIN;
		return 0;
	case '2':
		current_menu = MENU_MESSAGES;
		print_current_messages(ch);
		print_severity_prompt(ch);
		return 1;
	case '9':
		// restore factory settings
	}
	vcom_putchar(ch, '[');
	if(c == '\n' || c == '\r') {
		vcom_putstring(ch, "whitespace");
	} else {
		vcom_putchar(ch, c);

	}
	vcom_putstring(ch, "] -> Unknown Command, please try again\r\n");
	return 1;
}

uint8_t handle_messages(uint8_t ch, uint8_t c){
	vcom_putstring(ch, "not yet\r\n");
	current_menu = MENU_MAIN;
	return 0;

}

uint8_t handle_restore_factory(uint8_t ch){

	return 0;
};

// callback for each character received from
uint8_t vcom_process_input(uint8_t ch, uint8_t c) {
	if (currentChar >= MAX_MESSAGE_LEN){
		memset(&message, 0, MAX_MESSAGE_LEN);
		currentChar = 0;

		vcom_putstring(ch, MESSAGE_TOO_LONG);
		return 0;
	}
	if(c != '\n') {
		message[currentChar++] = c;
		return 1;
	}

	// newline, process the message


	switch(current_menu){
		case MENU_MAIN:
			handle_main_menu(ch); break;
		case MENU_MESSAGES:
			handle_messages(ch, c); break;
		case MENU_RESTORE_FACTORY:
			handle_restore_factory(ch); break;
		default:
			vcom_putstring(ch, "Unexpected state, please unplug and plug The Button back in\r\n");
			break;
	}

	memset(&message, 0, MAX_MESSAGE_LEN);
	currentChar = 0;

	return 0; // 1 == prompt requested
}




