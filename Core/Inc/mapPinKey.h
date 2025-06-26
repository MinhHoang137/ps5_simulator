/*
 * mapPinKey.h
 *
 *  Created on: Jun 17, 2025
 *      Author: Admin
 */

#ifndef INC_MAPPINKEY_H_
#define INC_MAPPINKEY_H_
#include "main.h"
typedef struct __attribute__((packed)) {
    uint8_t report_id;      // luôn = 0x01
    uint8_t modifier;       // 8 bit: Ctrl, Shift, Alt, GUI...
    uint8_t reserved;       // dự trữ, không dùng
    uint8_t keycodes[6];    // tối đa 6 phím nhấn cùng lúc
} KeyboardReport_t;
typedef struct __attribute__((packed)) {
    uint8_t report_id;  // luôn = 0x02
    uint8_t buttons;    // 3 bit dùng cho nút, 5 bit padding
    int8_t  x;          // dịch chuyển X
    int8_t  y;          // dịch chuyển Y
    int8_t  wheel;      // cuộn
} MouseReport_t;

typedef struct{
    uint16_t pin;        // chân GPIO
    uint8_t keycode;    // mã phím tương ứng
} MapPinKey;

typedef struct{
    uint16_t pin;        // chân GPIO
    uint8_t button;     // mã nút chuột (1, 2, 3)
} MapPinMouse;

void AddKeyToReport(KeyboardReport_t *report, uint8_t keycode);
void AddMouseButtonToReport(MouseReport_t *report, uint8_t button);
void AddModifierToReport(KeyboardReport_t *report, uint8_t modifier);
void CreateKeyboardReport(KeyboardReport_t *report);
void CreateMouseReport(MouseReport_t *report);
#endif /* INC_MAPPINKEY_H_ */
