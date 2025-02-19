/*
 * GccApplication3.c
 *
 * Created: 10/10/2024 12:32:01 PM
 * Author : dspproject
 */ 
#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
uint8_t current_led=2;
/*
void push_button(int i)
{
	
			_delay_ms(50);
			if(!(PINA & (1<<3)))
			{
				led_st=!led_st;
				if(led_st)
					{
						PORTB |= 1 << i;
					}
				else
					{
						PORTB &= ~(1 << i);
						_delay_ms(50);
						PORTB |= 1 << (i+1);
					}
			}
		
	
	
}
*/
void aprinde(uint8_t led)
{
	PORTB |= 1 << led;
}
void stinge(uint8_t led)
{
	PORTB &= ~(1 << led);
}
void comutare()
{
	if (!(PINA & (1<<3)))
	{
		_delay_ms(50);
		stinge(current_led);
		current_led++;
		if (current_led>5)
			current_led=2;
		aprinde(current_led);
		while(!(PINA & (1<<3)));
		_delay_ms(50);
	}
	if (!(PINA & (1<<2)))
	{
		_delay_ms(50);
		stinge(current_led);
		current_led--;
		if (current_led<2)
		current_led=5;
		aprinde(current_led);
		while(!(PINA & (1<<2)));
		_delay_ms(50);
	}
}
int main(void)
{
	//led
	DDRB |= ((1 << 2)|(1<<3)|(1<<4)|(1<<5));
	//button
	DDRA&=~((1<<3)|(1<<2));
	aprinde(current_led);
	while (1) 
    {
		comutare();
    }
}

