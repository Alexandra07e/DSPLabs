/*#include <lpc22xx.h>


int main(void)
{
	volatile unsigned int i = 0;
	PINSEL1 &= ~((1 << 27) | (1 << 26));
	PINSEL0 |= (1<<14)|(1<<15);
	
	IO0DIR |= (1u << 29)|(1u<<7);
	while(1)
	{
		IO0SET = 1u << 7;
		IO0SET = 1u << 29;
		for (i = 0; i < 500000; i++);
		IO0CLR = 1u << 7;
		IO0CLR = 1u << 29;
		for (i = 0; i < 500000; i++);
	}
	return 0;
}

*/