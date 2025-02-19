#include <lpc22xx.h>
#include <stdint.h>

/*void timer_init()  
{
	T0TCR=0x02;//resetare
	T0PR=13;
	T0MR0=12000000; //match la 12 ms
	T0MCR=0x04;//stop
	T0TCR=0x01 ;//set 
	
}*/

void timer_init1()  //cu intrerupere
{
	T0MCR |=(3<<0);
	T0MR0 = 12000000;
	T0TCR |= (1<<0);
}

void delay_ms()
{
	for(int i=0; i<1200000; i++);
	/*{
		T0TCR=0x02;
		//T0MR0=1000;
		T0TCR=0x01;
		while(!(T0IR & 0x01));
		T0IR=0x01;
	}*/
}

