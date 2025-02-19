#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "hex.h"
//_SEI();
void aprindere()
{
	PORTB|=1<<2;
	
}
void stingere()
{
	PORTB&=~(1<<2);
}


void timer_init()
{

	unsigned int n = 0x5A00;
	OCR1AH = (n >> 8) & 0xFF;
	OCR1AL = (n & 0xFF);
	TCCR1A=0x00;
	TCCR1B |= (1<<3) | (1<<2);
}

void timer_init1()
{
	unsigned int n = 0x5A00;
	OCR1AH = (n >> 8) & 0xFF;
	OCR1AL = (n & 0xFF);
	TCCR1A=0x00;
	TCCR1B |= (1<<3) | (1<<2);
	TIMSK|=(1<<OCIE1A);
	sei();
}
int counter=0;

ISR(TIMER1_COMPA_vect)
{
	counter = (counter+1)%10;
	display_digit(counter);
}

void time_reset()
{
	TIFR |= (1<<OCF1A);
}