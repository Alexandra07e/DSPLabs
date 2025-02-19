#define F_CPU 14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
//#define FOSC 1843200
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1
#include "Serial.h"
#include <util/delay.h>
#include <stdio.h>

/*
int main(void)
{
	USART_Init(0x5F);
	//_delay_ms(100);

	USART_Transmit('a');
	_delay_ms(1000);
	//unsigned char received_data=USART_Receive();
	
}*/

int main( void )
{
	char text[100];
	uint32_t counter = 0;
	//unsigned char received_data;
	USART_Init ( MYUBRR );
	sei();
	while(1)
	{
		if(flag)
		{
		sprintf(text, "some text %ld", counter);
		counter++;
		//_delay_ms(50);
		send_string(text);
		//USART_Transmit('a');
		unsigned char received_data=USART_Receive();
		USART_Transmit((received_data));
		flag=0;
		}
		
	}
	cli();
	//return 0;
}