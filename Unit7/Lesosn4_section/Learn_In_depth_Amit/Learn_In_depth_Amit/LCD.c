/*
 * LCD.c
 *
 * Created: 7/3/2022 9:00:36 PM
 *  Author: Mohamed Adel
 
 
****************************************************
LCD Driver for Atmega32 with an interface to a keypad
****************************************************


 */ 

#include "LCD.h"
#define FOUR_BIT_MODE
void gpio_init(void)
{
	
	//setting PORTA as output
	DDRA = 0xff;
	//Setting PORTB Pins 1 ,2,3 as outputs
	DDRB |= (0b111<<1);
}

void LCD_CMD(unsigned char cmd)
{
	is_busy();
	#ifdef EIGHT_BIT_MODE
	//Port A = cmd
	LCD_DATA = cmd;
	//1-Initialize reset with 0
	PORTB &= ~ (1<<LCD_RS);
	//2-Initialize RW with 0
	PORTB &= ~ (1<<LCD_RW);
	LCD_Enable_Function();
	#endif
	#ifdef FOUR_BIT_MODE
	PORTA= (LCD_DATA & 0x0f) | (cmd & 0xf0);
	//1-Initialize reset with 0
	PORTB &= ~ (1<<LCD_RS);
	//2-Initialize RW with 0
	PORTB &= ~ (1<<LCD_RW);
	LCD_Enable_Function();
	LCD_DATA= (LCD_DATA & 0x0f) | (cmd << 4);
	//1-Initialize reset with 0
	PORTB &= ~ (1<<LCD_RS);
	//2-Initialize RW with 0
	PORTB &= ~ (1<<LCD_RW);
	LCD_Enable_Function();
	
	#endif
	
	
}

void LCD_init(void)
{
	is_busy();
	//wait for more than 15ms after VCC reaches 4.5V
	_delay_ms(20);
	LCD_CMD(0x0C);
	_delay_ms(20);
	#ifdef EIGHT_BIT_MODE
	//Initiallize the LCD as 16*2 LCD 8 bit mode
	LCD_CMD(0x38);
	_delay_ms(1);
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_CMD(LCD_Return_home);
	LCD_CMD(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_CMD(LCD_DISP_ON_CURSOR_BLINK);
	clear_screen();
	_delay_ms(100);
	LCD_CMD(LCD_ENTRY_DEC);
	
	
}

void LCD_Write(unsigned char Data)
{
	#ifdef EIGHT_BIT_MODE
	is_busy();
	//Loading the data to PortA
	LCD_DATA = Data ;
	 // Reset = 1 means that it's Data if it's zero means that it's an address
	PORTB |= (1<<LCD_RS);
	//Clearing the RW
	PORTB &=~(1<<LCD_RW);
	_delay_ms(1);
	LCD_Enable_Function();
	#endif
	#ifdef FOUR_BIT_MODE
	PORTA= (Data & 0xF0);
	PORTB |= (1<<LCD_RS);
	//Clearing the RW
	PORTB &=~(1<<LCD_RW);
	LCD_Enable_Function();
	LCD_DATA= (Data << 4);
	PORTB |= (1<<LCD_RS);
	//Clearing the RW
	PORTB &=~(1<<LCD_RW);
	LCD_Enable_Function();
	#endif

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
	LCD_DATA_Dir  &=~(0xff<<4);
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
