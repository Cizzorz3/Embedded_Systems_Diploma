/*
 * UART.c
 *
 * Created: 7/14/2022 1:39:17 PM
 *  Author: Mohamed Adel
 */ 
#include "UART.h"
void uart_init(void)
{
	//Baud rate
	UBRRL = 51;
	
	Clear_Bit(UCSRA,U2X);
	//Frame
	Sit_Bit(UCSRB,TXEN);
	Clear_Bit(UCSRA,UDRE);
	//Enable
	Sit_Bit(UCSRB,RXEN);
	
}
void uart_send(uint8_t Data)
{
	while(!Read_Bit(UCSRA,UDRE));
	UDR = Data;
	
}
uint8_t uart_recieve(void)
{
	while(!Read_Bit(UCSRA,RXC));
	return UDR;
}
//synchronous
void uart_send_string(uint8_t *Data )
{
	uint8_t *p = Data;
	while(*p!='#')
	{
		uart_send(*p);
		p++;
	}
}
uint8_t uart_recieve_string(void)
{
	uint8_t *p = UDR;
	while(*p!='#')
	{
		if(!Read_Bit(UCSRA,RXC));
		p++;
		return UDR;
	}
}
void uart_send_int(uint32_t Data)
{
	uint8_t *p = &Data;
	uart_send(p[0]);
	uart_send(p[1]);
	uart_send(p[2]);
	uart_send(p[3]);
}

uint32_t uart_recieve_int(void)
{
	uint32_t i;
	uint8_t *p = &i;
	p[0] = uart_recieve();
	p[1] = uart_recieve();
	p[2] = uart_recieve();
	p[3] = uart_recieve();
	return i;
}