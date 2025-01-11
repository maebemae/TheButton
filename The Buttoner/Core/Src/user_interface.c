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
	vcom_putstring(ch, "Here would be the messages\r\n");
}
void print_severity_prompt(uint8_t ch){

}

uint8_t handle_main_menu(uint8_t ch) {
	if(currentChar < 1) {
		vcom_putstring(ch, "Unknown Command, please try again\r\n");
		return 1;
	}

	char c = message[0];
	switch(c) {
	case '0':
		print_current_messages(ch);
		current_menu = MENU_MAIN;
		return 0;
	case '1':
		current_menu = MENU_MESSAGES;
		print_current_messages(ch);
		print_severity_prompt(ch);
		return 1;
	case '9':
		// restore factory settings
	}

	vcom_putstring(ch, "Unknown Command, please try again\r\n");
	return 1;
}

uint8_t handle_messages(uint8_t ch, uint8_t c){
	vcom_putstring(ch, "not yet");
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
			return handle_main_menu(ch); break;
		case MENU_MESSAGES:
			return handle_messages(ch, c); break;
		case MENU_RESTORE_FACTORY:
			return handle_restore_factory(ch); break;
	}
	vcom_putstring(ch, "Unexpected state, please unplug and plug The Button back in\r\n");
	return 0; // 1 == prompt requested
}




