/*
 * adc_control.c
 *
 *  Created on: Jun 17, 2025
 *      Author: Admin
 */

#include "main.h"
#include "stdlib.h"
#include "adc_control.h"
extern ADC_HandleTypeDef hadc1;

uint16_t adc_buffer[ADC_BUFFER_SIZE]; 
extern int mouse_x; // Biến toàn cục để lưu trữ giá trị dịch chuyển chuột theo trục X
extern int mouse_y; // Biến toàn cục để lưu trữ giá trị dịch chuyển chuột theo trục Y
extern int move_x; // Biến toàn cục để lưu trữ giá trị dịch chuyển joystick theo trục X
extern int move_y; // Biến toàn cục để lưu trữ giá trị dịch chuyển joystick theo trục Y

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
    if (hadc == &hadc1) {
        move_x = ConvertADCValues(adc_buffer[0]); // Chuyển đổi giá trị ADC từ kênh 0
        move_y = ConvertADCValues(adc_buffer[1]); // Chuyển đổi giá
        mouse_x = ConvertADCValues(adc_buffer[2]); // Chuyển đổi giá trị ADC từ kênh 2
        mouse_y = ConvertADCValues(adc_buffer[3]); // Chuyển đổi giá trị ADC từ kênh 3
    }
}



int ConvertADCValues(uint16_t value){
    int rawValue = (int)value; // Chuyển đổi giá trị ADC sang kiểu int
    rawValue -= 2048; // Giả sử giá trị ADC nằm trong khoảng 0-4095, trừ đi 2048 để đưa về khoảng -2048 đến 2047
    int deadzone = 200; // Giả sử bạn muốn bỏ qua các giá trị nhỏ hơn 10
    int upper_limit = 50;
    double scale = upper_limit * 1.0 / 2048.0; 
    if (abs(rawValue) < deadzone) {
        return 0; // Trả về 0 nếu giá trị nhỏ hơn deadzone
    }
    int converted_value = (int)(rawValue * scale);
    if (converted_value > upper_limit) {
        converted_value = upper_limit; // Giới hạn giá trị tối đa là 127
    } else if (converted_value < -upper_limit) {
        converted_value = -upper_limit; // Giới hạn giá trị tối thiểu là -127
    }
    return converted_value; // Trả về giá trị đã chuyển đổi
}
