#define F_CPU 14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <util/delay.h>

void initADC()
{
	DDRA &=~(1<<1);
	ADCSRA = (1<<ADEN) |(1<<ADPS1)|(1<<ADPS0);
	ADMUX=(1<<REFS0)| 1;
}


uint16_t readADC()
{
	uint8_t lsb,msb;
	uint16_t adc_val;
	ADCSRA|=(1<<ADSC);
	while((ADCSRA&(1<<ADSC)));
	lsb=ADCL;
	msb=ADCH;
	adc_val=msb;
	adc_val=adc_val<<8;
	adc_val|=lsb;
	return adc_val;
}
