//
// Created by valy on 14.04.2025.
//

#include "demo_task.h"

#include <stdio.h>
#include <stdint.h>

#include "cmsis_os2.h"
#include "main.h"
#include "stm32f4xx_hal_gpio.h"
#include "usbd_cdc_if.h"
#include "FreeRTOS_Helpers.h"

/*void MyDemoTask(void)
{
	static uint32_t n = 0;
	static char text[1000];
	if (n % 2)
	{
		HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_SET);
	}
	n++;

	sprintf (text,"Hello %d\n", n);
	CDC_Transmit_FS(text,strlen(text));
}*/
int led_st = 0;
void push_button_task(void)
{
	//HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin, 0);
	int j;

	while (1){
		j=HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0); //0-nu e apasat
		if(!j)
		{
			//for (int i=0;i<100;i++);
			j=HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
			if (!j)
			{
				led_st=!led_st;
				if (led_st)
					HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_SET);
				else
					HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_RESET);

				while (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0));
			}
		}
	}
}

int count = -1;
void push_one_button_at_a_time(void)
{
	HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_RESET);
	int j;

	while (1){
		j=HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0); //0-nu e apasat
		if(!j)
		{
			//for (int i=0;i<1000;i++);
			HAL_Delay(50);
			j=HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
			count++;
			if (!j)
			{
				switch (count)
				{
					case 0:
					{
							HAL_GPIO_WritePin(GPIOD, LD3_Pin, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_RESET);
							break;
					}
					case 1:
					{
							HAL_GPIO_WritePin(GPIOD, LD4_Pin, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOD, LD3_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_RESET);
							break;
					}
					case 2:
					{
							HAL_GPIO_WritePin(GPIOD, LD5_Pin, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOD, LD3_Pin|LD4_Pin|LD6_Pin, GPIO_PIN_RESET);
							break;
					}
					case 3:
					{
							HAL_GPIO_WritePin(GPIOD, LD6_Pin, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOD, LD3_Pin|LD4_Pin|LD5_Pin, GPIO_PIN_RESET);
							break;
					}
				}
			}
			if (count == 4)
			{
				count = -1;
				HAL_GPIO_WritePin(GPIOD, LD3_Pin|LD4_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_RESET);
			}

			while (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0));
		}
	}
}
static const uint8_t digit_map[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void display(uint8_t digit)
{
	for(int i=0;i<8;i++) //verificam fiecare bit in parte (e pe 8 biti)
	{
		HAL_GPIO_WritePin(GPIOB, 1<<i,
		(digit_map[digit] & (1<<i) ? GPIO_PIN_SET : GPIO_PIN_RESET));
	}
}

void clear()
{
	for(int i=0;i<8;i++)
		HAL_GPIO_WritePin(GPIOB, 1<<i,GPIO_PIN_RESET);
}

void seven_segment_display_task(void)
{
	int i=0;
	while (i!=10)
	{
		display(i);
		HAL_Delay(1000);
		i++;
	}
}
