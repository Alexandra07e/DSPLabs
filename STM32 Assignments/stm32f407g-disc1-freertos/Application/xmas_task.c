//
// Created by lika on 11/28/25.
//


#include "xmas_task.h"

#include <stdio.h>
#include <stdint.h>
#include "main.h"
#include "stm32f4xx_hal_gpio.h"
#include "usbd_cdc_if.h"

void MyXmasTask(void)
{
    static uint32_t n = 0;

    int button = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
    static int last_button = 0;

    if (button == GPIO_PIN_SET && last_button == GPIO_PIN_RESET)
    {
        n++;
    }

    last_button = button;

    switch (n % 4) {
        case 0: {
            HAL_GPIO_WritePin(GPIOD, LD3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD6_Pin|LD5_Pin, GPIO_PIN_RESET);
            break;
        }
        case 1: {
            HAL_GPIO_WritePin(GPIOD, LD4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, LD3_Pin|LD6_Pin|LD5_Pin, GPIO_PIN_RESET);
            break;
        }
        case 2: {
            HAL_GPIO_WritePin(GPIOD, LD6_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, LD3_Pin|LD4_Pin|LD5_Pin, GPIO_PIN_RESET);
            break;
        }
        case 3: {
            HAL_GPIO_WritePin(GPIOD, LD5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, LD3_Pin|LD4_Pin|LD6_Pin, GPIO_PIN_RESET);
            break;
        }
    }
    static char text[1000];

    sprintf (text,"Hello, world %d\n", n);
    CDC_Transmit_FS(text,strlen(text));
}
