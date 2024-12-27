/*
 * hid_converter.h
 *
 *  Created on: Dec 27, 2024
 *      Author: mae
 */

#ifndef INC_HID_CONVERTER_H_
#define INC_HID_CONVERTER_H_

#include <stdint.h>
#include "usb_class_hid.h"

#define HID_LEFT_SHIFT 0x02
#define HID_KEY_A 0x04
#define HID_KEY_0 0x27
#define HID_KEY_1 0x1e



void charToHidReport(char from, uint8_t *report );


#endif /* INC_HID_CONVERTER_H_ */
