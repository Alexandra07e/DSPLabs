
//led
/*#include <lpc22xx.h>


int main(void)
{
	volatile unsigned int i = 0;
	PINSEL1 &= ~((1 << 27) | (1 << 26));
	IO0DIR |= 1u << 29;
	while(1)
	{
		IO0SET = 1u << 29;
		for (i = 0; i < 500000; i++);
		IO0CLR = 1u << 29;
		for (i = 0; i < 500000; i++);
	}
	return 0;
}
*/



#include <lpc22xx.h>
#include <stdint.h>

uint8_t led_st=0;
int main(void)
{
	volatile unsigned int i = 0;
	PINSEL1 &= ~((1 << 27) | (1 << 26));
	PINSEL0 &= ~((1<<14)|(1<<15));
	
	IO0DIR |= (1u << 29);
	IO0DIR &= ~(1u << 7);
	
	IO0SET |= 1u<<7;
	while(1)
	{
		if(!(IO0PIN & (1u<<7)))
		{
		  for (i = 0; i < 50000; i++);
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
				IO0CLR = 1u << 7;
			}
	}
}
	return 0;
}

