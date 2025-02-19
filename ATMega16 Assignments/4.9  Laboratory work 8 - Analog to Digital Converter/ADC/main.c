/*
 * ADC.c
 *
 * Created: 11/15/2024 1:05:26 PM
 * Author : dspproject
 */ 
#define F_CPU 14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <util/delay.h>
#include "ADC.h"
#include "Serial.h"

int main(void)
{
	USART_Init(0x7);
    initADC();
    while (1) 
    {
		uint32_t val;
		uint32_t readVal;
		char text[100];
		readVal=readADC();
		val=readVal*5000/1023;
		sprintf(text, "ADCvalue %ld\n", val);
		send_string(text);
		_delay_ms(100);
    }
}

