/*
 * mapPinKey.c
 *
 *  Created on: Jun 17, 2025
 *      Author: Admin
 */
#include "mapPinKey.h"
#include "button_def.h"
#include "main.h"
extern uint8_t mouse_y; // Biến toàn cục để lưu giá trị dịch chuyển chuột theo trục Y
MapPinKey mpkArray[] = {
    {btnE_Pin, KEY_E}, // Nút E
    {btnQ_Pin, KEY_Q}, // Nút Q 
    {btnTab_Pin, KEY_TAB}, // Nút Tab
    {btnZ_Pin, KEY_Z}, // Nút Z
    {btn1_Pin, KEY_1}, // Nút 1
    {btn2_Pin, KEY_2}, // Nút 2
    {btn3_Pin, KEY_3}, // Nút 3
    {btn4_Pin, KEY_4}, // Nút 4
    {btnSpace_Pin, KEY_SPACE}, // Nút Space
    {btnX_Pin, KEY_X}, // Nút X
    {btnL_Pin, KEY_L}, // Nút L
    {btnEsc_Pin, KEY_ESC}, // Nút Esc
}; 

MapPinKey alternateArray[] = { // giá trị thay thế khi ấn PA0 kèm chân tương ứng
    {btnZ_Pin, KEY_F},
    {btnQ_Pin, KEY_G},
    {btnE_Pin, KEY_B},
    {btn1_Pin, KEY_T},
    {btn3_Pin, KEY_R},
};
MapPinMouse mpmArray[] = {
    {leftMouse_Pin, MOUSE_BTN_LEFT}, // Nút chuột trái
    {rightMouse_Pin, MOUSE_BTN_RIGHT}, // Nút chuột phải
};

MapPinKey mpMod[] = { // Mảng chứa các phím modifier
    {btnX_Pin, MOD_LCTRL},
    {btnSpace_Pin, MOD_LSHIFT},
    {btnL_Pin, MOD_LALT}
};
void AddKeyToReport(KeyboardReport_t *report, uint8_t keycode) {
    for (int i = 0; i < 6; i++) {
        if (report->keycodes[i] == 0) { // Tìm vị trí trống
            report->keycodes[i] = keycode;
            return;
        }
    }
}
void AddMouseButtonToReport(MouseReport_t *report, uint8_t button) {
    report->buttons |= button; // Thêm nút vào báo cáo
}
void AddModifierToReport(KeyboardReport_t *report, uint8_t modifier) {
    report->modifier |= modifier; // Thêm modifier vào báo cáo
}

uint8_t IsModifiableKey(uint16_t pin) {
    // Kiểm tra xem keycode có phải là phím có thể thay thế không
    for (int i = 0; i < sizeof(alternateArray) / sizeof(MapPinKey); i++) {
        if (alternateArray[i].pin == pin) {
            return 1; // Có thể thay thế
        }
    }
    return 0; // Không thể thay thế
}



void CreateKeyboardReport(KeyboardReport_t *report) {
    report->report_id = 0x01; // ID báo cáo bàn phím
    int size = sizeof(mpkArray) / sizeof(MapPinKey);
    int alternateSize = sizeof(alternateArray) / sizeof(MapPinKey);
    int modSize = sizeof(mpMod) / sizeof(MapPinKey);
    uint8_t isModifierPressed = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET; // Kiểm tra nút PA0
    if (isModifierPressed) {
        // Nếu PA0 được nhấn và phím có thể thay thế, sử dụng giá trị thay thế
        for (int j = 0; j < alternateSize; j++) {
            if (HAL_GPIO_ReadPin(GPIOF, alternateArray[j].pin) == GPIO_PIN_SET)
                AddKeyToReport(report, alternateArray[j].keycode);
        } 
        for (int i = 0; i < modSize; i++) {
            if (HAL_GPIO_ReadPin(GPIOF, mpMod[i].pin) == GPIO_PIN_SET) {
                AddModifierToReport(report, mpMod[i].keycode);
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
        if (HAL_GPIO_ReadPin(GPIOF, mpkArray[i].pin) == GPIO_PIN_SET) {
                AddKeyToReport(report, mpkArray[i].keycode);
            }
        }
    }
    
}

void CreateMouseReport(MouseReport_t *report) {
    report->report_id = 0x02; // ID báo cáo chuột
    int size = sizeof(mpmArray) / sizeof(MapPinMouse);
    uint8_t isModifierPressed = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET; // Kiểm tra nút PA0
    for (int i = 0; i < size; i++) {
        if (HAL_GPIO_ReadPin(GPIOF, mpmArray[i].pin) == GPIO_PIN_SET) {
            AddMouseButtonToReport(report, mpmArray[i].button);
        }
    }
    if (isModifierPressed) {
        if (HAL_GPIO_ReadPin(GPIOF, btn2_Pin) == GPIO_PIN_SET) {
            report->wheel = 1; // Dịch chuyển lên
        } else if (HAL_GPIO_ReadPin(GPIOF, btn4_Pin) == GPIO_PIN_SET) {
            report->wheel = -1; // Dịch chuyển xuống
        } else {
            report->wheel = 0; // Không dịch chuyển
        }
    } 
}

