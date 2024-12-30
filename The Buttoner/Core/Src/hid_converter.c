/*
 * hid_converter.c
 *
 *  Created on: Dec 27, 2024
 *      Author: mae
 */

#include "hid_converter.h"

// https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf

void charToHidReport(char character, uint8_t *report) {
	uint8_t modifier = 0;
	uint8_t key = 0;

	if (character >= 'a' && character <= 'z') {
		uint8_t offset = character - 'a';
		key = offset + HID_KEY_A;
	} else if (character >= 'A' && character <= 'Z') {
		modifier = HID_LEFT_SHIFT;
		uint8_t offset = character - 'A';
		key = offset + HID_KEY_A;
	} else if (character == '0') {
		key = HID_KEY_0;
	} else if (character >= '1' && character <= '9') {
		uint8_t offset = character - '1';
		key = offset + HID_KEY_1;
	} else {
		switch (character) {
		case '!':
			modifier = HID_LEFT_SHIFT;
		case '1':
			key = 0x1E;
			break;
		case '@':
			modifier = HID_LEFT_SHIFT;
		case '2':
			key = 0x1F;
			break;
		case '#':
			modifier = HID_LEFT_SHIFT;
		case '3':
			key = 0x20;
			break;
		case '$':
			modifier = HID_LEFT_SHIFT;
		case '4':
			key = 0x21;
			break;
		case '%':
			modifier = HID_LEFT_SHIFT;
		case '5':
			key = 0x22;
			break;
		case '^':
			modifier = HID_LEFT_SHIFT;
		case '6':
			key = 0x23;
			break;
		case '&':
			modifier = HID_LEFT_SHIFT;
		case '7':
			key = 0x24;
			break;
		case '*':
			modifier = HID_LEFT_SHIFT;
		case '8':
			key = 0x25;
			break;
		case '(':
			modifier = HID_LEFT_SHIFT;
		case '9':
			key = 0x26;
			break;
		case ')':
			modifier = HID_LEFT_SHIFT;
		case '0':
			key = 0x27;
			break;
		case '\n':
			key = 0x28;
			break;
		case '\t':
			key = 0x2b;
			break;
		case ' ':
			key = 0x2c;
			break;
			// Here go characters needing shift, fall-through to same character without shift,
		case '_':
			modifier = HID_LEFT_SHIFT;
		case '-':
			key = 0x2D;
			break;
		case '+':
			modifier = HID_LEFT_SHIFT;
		case '=':
			key = 0x2E;
			break;
		case '{':
			modifier = HID_LEFT_SHIFT;
		case '[':
			key = 0x2F;
			break;
		case '}':
			modifier = HID_LEFT_SHIFT;
		case ']':
			key = 0x30;
			break;
		case '|':
			modifier = HID_LEFT_SHIFT;
		case '\\':
			key = 0x31;
			break;
			// #/~?
		case ':':
			modifier = HID_LEFT_SHIFT;
		case ';':
			key = 0x33;
			break;
		case '"':
			modifier = HID_LEFT_SHIFT;
		case '\'':
			key = 0x34;
			break;
		case '~':
			modifier = HID_LEFT_SHIFT;
		case '`':
			key = 0x35;
			break;
		case '<':
			modifier = HID_LEFT_SHIFT;
		case ',':
			key = 0x36;
			break;
		case '>':
			modifier = HID_LEFT_SHIFT;
		case '.':
			key = 0x37;
			break;
		case '?':
			modifier = HID_LEFT_SHIFT;
		case '/':
			key = 0x38;
			break;

		default:
			// unsupported
		}
	}

	report[0] = modifier;
	report[2] = key;

}
