/*
 *  Author : Mohamed Adel
 *
 *
 *************************
 * Driver to enable the GPIOA & GPIOB with two push buttons as input connected with PA1 and PA13
 * and output on port B on PB1 and PB13 with single pressing and multipressing on the push buttons
 * and configuring the inputs as open drain inputs
 *
 * */

#include "STM32f103C6.h"
#include "STM_F103C6_GPIO_Driver.h"
#include "LCD.h"
#include  "Keypad_Driver.h"
#include "Seven_Segment.h"
void clock_init(void)
{
	//Enabling the clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}
int main (void)
{
	clock_init();
	gpio_init();
	LCD_init();
	seven_segment_init();
	seven_segment_start();
	keypad_init();
	Send_string("Key pad is ready");
	_delay_ms(500);
	char pressed_key ;
	    while (1)
	    {
			pressed_key = keyoad_getchar();
			switch(pressed_key)
			{
				case ('!'):
					clear_screen();
					break;
				case ('A'):
					break;
				default:
					LCD_Write(pressed_key);
					break;
			}
	    }
}
