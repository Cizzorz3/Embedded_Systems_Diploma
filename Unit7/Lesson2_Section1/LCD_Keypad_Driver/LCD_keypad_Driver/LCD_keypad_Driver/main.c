/*
 * LCD_keypad_Driver.c
 *
 * Created: 6/23/2022 8:59:06 PM
 * Author : Mohamed Adel
 */ 

#include <avr/io.h>
#include "LCD_Driver/LCD.h"
#include "Keypad_Driver/Keypad_Driver.h"
int main(void)
{
	gpio_init();
	keypad_init();
	LCD_init();
	char pressed_key ;
    while (1) 
    {
		pressed_key = keyoad_getchar();
		switch(pressed_key)
		{
			case ('!'):
				clear_screen();
				break;
			case ('N'):
				break;
			default:
				LCD_Write(pressed_key);
				break;
		}
    }
}

