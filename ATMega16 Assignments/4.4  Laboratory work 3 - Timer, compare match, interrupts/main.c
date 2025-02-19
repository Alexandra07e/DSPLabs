/*
 * lab3.c
 *
 * Created: 10/24/2024 10:04:55 AM
 * Author : dspproject
 */ 

#define F_CPU 14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "timer.h"
//_SEI();


int main(void)
{/*
				if ((TIFR & (1 << 4)) != 0)
				{
					PORTB^=(1<<2);
					time_reset();
				}
	*/
    DDRB |=(1<<2);
	stingere();
	timer_init1();
    while (1) 
    {
				
    }

}

