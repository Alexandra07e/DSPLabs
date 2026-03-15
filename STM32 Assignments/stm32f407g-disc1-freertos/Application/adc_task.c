//
// Created by lika on 12/5/25.
//

//
// Created by lika on 11/28/25.
//


#include "xmas_task.h"

#include <stdio.h>
#include <stdint.h>
#include "main.h"
#include "stm32f4xx_hal_gpio.h"
#include "adc.h"
#include "usbd_cdc_if.h"

void MyADCFunction(void)
{
    uint16_t adc_raw;
    float voltage;
    static char text[100];

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 10);
    adc_raw = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    voltage = (adc_raw * 3.3f) / 4095.0f;

    snprintf(text, sizeof(text), "Voltage: %.2f V\r\n", voltage);
    CDC_Transmit_FS((uint8_t*)text, strlen(text));
}
