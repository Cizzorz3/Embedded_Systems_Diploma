/*
 * LCD.c
 *
 * Created: 7/14/2022 2:27:17 PM
 *  Author: Mohamed Adel
 
 
 ****************************************************
 LCD Driver for Atmega32 with an interface to a keypad
 ****************************************************
 */ 

/*
 * LCD.c
 *
 * Created: 6/23/2022 9:00:36 PM
 *  Author: Mohamed Adel
 
 
****************************************************
LCD Driver for Atmega32 with an interface to a keypad
****************************************************


 */ 

#include "LCD.h"

void gpio_init(void)
{
	
	//setting PORTA as output
	DDRA = 0xff;
	//Setting PORTB Pins 1 ,2,3 as outputs
	DDRB |= (0b111<<1);
}

void LCD_CMD(unsigned char cmd)
{
	//Port A = cmd
	LCD_DATA = cmd;
	//1-Initialize reset with 0
	PORTB &= ~ (1<<LCD_RS);
	//2-Initialize RW with 0
	PORTB &= ~ (1<<LCD_RW);
	//3-Sit the enable pin
	PORTB |= (1<<LCD_ENABLE);
	_delay_ms(2);
	//4-clear the enable pin
	PORTB &= ~ (1<<LCD_ENABLE);
	
	
}

void LCD_init(void)
{
	//checking if the LCD is busy
	is_busy();
	//wait for more than 15ms after VCC reaches 4.5V
	_delay_ms(20);
	LCD_CMD(0x0C);
	_delay_ms(20);
	//Initiallize the LCD as 16*2 LCD 8 bit mode
	LCD_CMD(0x38);
	_delay_ms(1);
	//Clearing the LCD
	LCD_CMD(0x01);
	_delay_ms(1);
	//return to home
	LCD_CMD(0x02);
	_delay_ms(1);
	//make increment in the cursor
	LCD_CMD(0x06);
	_delay_ms(1);
	//Go to the first line
	LCD_CMD(0x80);
	_delay_ms(1);
	
}

void LCD_Write(unsigned char Data)
{
	is_busy();
	//Loading the data to PortA
	LCD_DATA = Data ;
	 // Reset = 1 means that it's Data if it's zero means that it's an address
	PORTB |= (1<<LCD_RS);
	//Clearing the RW
	PORTB &=~(1<<LCD_RW);
	_delay_ms(1);
	LCD_Enable_Function();

}

void LCD_Enable_Function(void)
{
	//Disabling the enable pin
	LCD_CTRL_PORT &=~ (1<<LCD_ENABLE);
	//Delay till the enable cycle time reaches 500ns
	_delay_ms(40);
	//Enabling the LCD enable pin
	LCD_CTRL_PORT |= (1<<LCD_ENABLE) ;
}

void is_busy(void)
{
	 //setting the PORT A as input
	 LCD_DATA_Dir = 0x00;
	 //Put the LCD in read mode (RW on)
	 LCD_CTRL_PORT |= (1<<LCD_RW) ;
	 //put the LCD in command mode (RS off)
	 LCD_CTRL_PORT &=~ (1<<LCD_RS);
	 LCD_Enable_Function();
	 //setting PORT A as output
	 LCD_DATA_Dir = 0xff;
	 //Disable read mode
	 LCD_CTRL_PORT &=~ (1<<LCD_RW);
	 

}

void clear_screen(void)
{
	LCD_CMD(LCD_CLEAR_SCREEN);
}

void Send_string(char * data)
{
	int count = 0 ;
	while(*data != 0)
	{
		count++;
		LCD_Write(*data++);
		//LCD can only hold 16 char in one line
		if(count ==16)
		{
			LCD_XY(2,0);
		}
		//if the two lines are  full
		else if(count ==32)
		{
			//clear the screen
			clear_screen();
			//go to the first line
			LCD_XY(1,0);
			count = 0;
		}
	}
}

void LCD_XY(int row , int col)
{
	if(row ==1)
	{
		LCD_CMD(LCD_BEGIN_AT_FIRST_ROW+col)	;
	}
	else if(row ==2)
	{
		LCD_CMD(LCD_BEGIN_AT_SECOND_ROW+col);
	}
}
