#define F_CPU 14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <util/delay.h>

volatile unsigned char flag=0;
volatile unsigned char data=0;

ISR(USART_RXC_vect)
{
	flag=1;
	//data=UDR;
	//USART_Transmit(data);
}


void USART_Transmit(unsigned char data)
{
	
	while ( !( UCSRA & (1<<UDRE)) );
	
	UDR = data;
}
unsigned char USART_Receive( void )
{
	
	while ( !(UCSRA & (1<<RXC)) );
	
	return UDR;
}
void USART_Init( unsigned int ubrr)
{
	//DDRD&=(1<<PD0);
	DDRD |=(1<<1);
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	UCSRB |= (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	UCSRC |= (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	
	//sei();
}



void send_string(char *sir)
{
	for(int i=0; i<strlen(sir);i++)
	{
		USART_Transmit(sir[i]);
	}
}