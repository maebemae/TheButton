/*
 * hid_converter.c
 *
 *  Created on: Dec 27, 2024
 *      Author: mae
 */

#include "hid_converter.h"

	// https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf


void charToHidReport(char character, uint8_t *report) {

	if(character == 0)
		return;
	if (character >= 'a' && character <= 'z') {
		uint8_t offset = character - 'a';
		report[2] = offset + HID_KEY_A;
	} else if (character >= 'A' && character <= 'Z') {
		report[0] = HID_LEFT_SHIFT;
		uint8_t offset = character - 'A';
		report[2] = offset + HID_KEY_A;
	} else if (character == '0') {
		report[2] = HID_KEY_0;
	}
	else if (character >= '1' && character <= '9') {
		uint8_t offset = character - '1';
		report[2] = offset + HID_KEY_1;
	} else {
		switch(character) {
		case '\n': report[2] = 0x29; break; // todo why isn't newline working?
		case '\t': report[2] = 0x2b; break;
		case ' ': report[2] = 0x2c; break;

		case '_': report[0] = HID_LEFT_SHIFT;
		case '-': report[2] = 0x2D;break;
		case '+': report[0] = HID_LEFT_SHIFT;
		case '=': report[2] = 0x2E; break;
		case '{': report[0] = HID_LEFT_SHIFT;
		case '[': report[2] = 0x2F; break;
		case '}': report[0] = HID_LEFT_SHIFT;
		case ']': report[2] = 0x30; break;
		case '|': report[0] = HID_LEFT_SHIFT;
		case '\\': report[2] = 0x31; break;

		// todo
		case '?':
		default: report[0] = HID_LEFT_SHIFT;

					report[2] = 0x38;
		}
	}

}
