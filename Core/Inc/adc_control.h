/*
 * adc_control.h
 *
 *  Created on: Jun 17, 2025
 *      Author: Admin
 */

#ifndef INC_ADC_CONTROL_H_
#define INC_ADC_CONTROL_H_
#include "main.h"
#define ADC_BUFFER_SIZE 4 // Giả sử bạn đã định nghĩa kích thước bộ đệm ADC
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
int ConvertADCValues(uint16_t value);

#endif /* INC_ADC_CONTROL_H_ */
