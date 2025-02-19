#ifndef __SERIAL_H
#define __SERIAL_H
uint8_t flag;

unsigned char USART_Receive( void );
void USART_Init( unsigned int ubrr);
void USART_Transmit( unsigned char data );
void send_string(char *text);
#endif