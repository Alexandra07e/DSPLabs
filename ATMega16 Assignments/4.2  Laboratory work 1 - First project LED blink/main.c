/*
 * GccApplication3.c
 *
 * Created: 10/10/2024 12:32:01 PM
 * Author : dspproject
 */ 
#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
uint8_t led_st=0;
void push_button()
{
	
	while(1)
	{
		if(!(PINA & (1<<2))){
			_delay_ms(50);
			if(!(PINA & (1<<2)))
			{
				led_st=!led_st;
				if(led_st)
					{
						PORTB |= 1 << 2;
					}
				else
					{
						PORTB &= ~(1 << 2);
					}
				while(!(PINA & (1<<2)));
			}
		}
	
	}
}


int main(void)
{
	//led
	DDRB |= (1 << 2);
	
	//button
	DDRA &= ~(1 << 2);
	
	while(1)
	{
		push_button();
	}
	
	
}

