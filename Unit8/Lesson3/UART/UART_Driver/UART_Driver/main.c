/*
 * UART_Driver.c
 *
 * Created: 7/14/2022 1:38:14 PM
 * Author : Mohamed Adel
 */ 
#include "UART/UART.h"
#include "LCD/LCD.h"
#include "avr/delay.h"
int main(void)
{
	char x;
    /* Replace with your application code */
	gpio_init();
	LCD_init();
	uart_init();
	uart_send('M');
	uart_send('o');
	uart_send('h');
	uart_send('a');
	uart_send('m');
	uart_send('e');
	uart_send('d');
	uart_send(' ');
	uart_send_string("Adel#");
	//Send_string("Mohamed");
    while (1) 
    {
		LCD_Write(uart_recieve());

	
    }
}

