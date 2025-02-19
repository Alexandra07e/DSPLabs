#include <lpc22xx.h>
#include <stdint.h>
#include "timer.h"

uint8_t led_st=0;

void push_button()
{
if(!(IO0PIN & (1u<<7)))
		{
			int i;
		  for (i = 0; i < 800000; i++);
			if(!(IO0PIN & (1u<<7)))
			{
				led_st=!led_st;
				if(led_st)
				{
					IO0SET = 1u << 29;
				}
				else
				{
					IO0CLR = (1u << 29);
				}
				while(!(IO0PIN & (1u<<7)));
				//IO0CLR = 1u << 7;
			}
	}
}
void aprindere(uint8_t led)
{
	IO0SET |= 1u << led;
}
void stingere(uint8_t led)
{
	IO0CLR |= (1u << led);
}

uint8_t current_led=29;

void comutare()
{
	if(!(IO0PIN&(1u<<8)))
	{
	//for(int i=0; i<500000; i++);
		delay_ms();
		stingere(current_led);
		current_led--;
		if(current_led==26){
			current_led=25;
		}
		if(current_led<25)
		{
			current_led=29;
		}
		aprindere(current_led);
		while(!(IO0PIN&(1u<<8)));
		//for(int i=0; i<600000; i++);
		delay_ms();
		
}
		if(!(IO0PIN&(1u<<7)))
		{
			//for(int i=0; i<500000; i++);
			delay_ms();
			stingere(current_led);
			current_led++;
			if(current_led==26){
				current_led=27;
			}		
			if(current_led>29)
			{
				current_led=25;
			}
			aprindere(current_led);
			while(!(IO0PIN&(1u<<7)));
			//for(int i=0; i<600000; i++);
			delay_ms();
}
}

int main(void)
{
	volatile unsigned int i = 0;
	//led
	PINSEL1 &= ~((1 << 27) | (1 << 26)); // 0.29--exit 26
	PINSEL1 &= ~((1 << 24) | (1 << 25)); //0.28--exit 24
	PINSEL1 &= ~((1 << 22) | (1 << 23)); //0.27--exit 22
	PINSEL1 &= ~((1 << 19) | (1 << 20));//0.25--exit 20
	
	//butoane
	PINSEL0 &= ~((1<<14)|(1<<15));  //exit 15, P0.7
	PINSEL0 &= ~((1<<16)|(1<<17)); //exit 17, P0.8
	
	IO0DIR |= (1u << 29);
	IO0DIR |= (1u << 28);
	IO0DIR |= (1u << 27);
	IO0DIR |= (1u << 25);
	
	IO0DIR &= ~(1u << 7);
	IO0DIR &= ~(1u << 8);
	
	IO0SET |= 1u<<7;
	//aprindere(current_led);
	timer_init1();
	while(1)
	{
		/*aprindere(current_led);
		delay_ms();
		stingere(current_led);
		delay_ms();*/
		comutare();
	}
	
	return 0;
}

