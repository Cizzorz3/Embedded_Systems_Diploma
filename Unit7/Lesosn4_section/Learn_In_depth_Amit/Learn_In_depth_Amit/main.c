/*
 * Learn_In_depth_Amit.c
 *
 * Created: 7/3/2022 8:37:48 PM
 * Author : Mohamed Adel
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
int main(void)
{
	gpio_init();
	LCD_init();
    /* Replace with your application code */
    while (1) 
    {
		Send_string("Learn In Depth");
		_delay_ms(1000);
		clear_screen();
    }
}

