#define F_CPU 14745600UL
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "timer.h"

static const uint8_t digitmap[10] = {
	0xC0,
	0xF9,
	0xA4,
	0xB0,
	0x99,
	0x92,
	0x82,
	0xF8,
	0x80,
	0x90
};

void init_digit(void)
{
	DDRB|=(0xFF);
}

void display_digit(uint8_t digit)
{
	PORTB= digitmap[digit];
}

void clear_digit(void)
{
	PORTB=0;
}


int i=0;

void change()
{
	
	display_digit(i);
	i++;
	if(i==10)
	i=0;
}


void f3()
{
	sei();
	timer_init1();
	init_digit();
	//TIMSK|=(1<<OCIE1A);
	while(1)
	{
		
	}
	clear_digit();
	cli();
}

int flag=1;
void f4()
{
	sei();
	timer_init1();
	init_digit();
	while(1)
	{
		if(flag)
		{
			change();
		}
		flag=0;
	}
	clear_digit();
	cli();
}
