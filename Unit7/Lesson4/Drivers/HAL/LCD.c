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

void LCD_Enable_Function()
{
	//	//Enabling the LCD enable pin
	MCAL_GPIO_WritePin(GPIOA, ENABLE, GPIO_Pin_SET);
	_delay_ms(40);
	//Disabling the enable pin
	MCAL_GPIO_WritePin(GPIOA, ENABLE, GPIO_Pin_Reset);
	//	//Delay till the enable cycle time reaches 500ns


}
void _delay_ms(uint32_t i)
{
	uint32_t x ,y ;
	for(x=0;x<i;x++)
	{
		for(y=0;y<255;y++);
	}
}
GPIO_Pinconfig_t PinCfg ;
void gpio_init(void)
{

	//setting PORTA as output
	//DDRA = 0xff;
	PinCfg.GPIO_Pin_Number =GPIO_PIN_0 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_1 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_2 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_3 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_4 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_5 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_6 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_7 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	//Setting PORTB Pins 1 ,2,3 as outputs
	PinCfg.GPIO_Pin_Number =GPIO_PIN_8 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_9 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_10 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	MCAL_GPIO_WritePin(GPIOA, ENABLE, GPIO_Pin_Reset);
	MCAL_GPIO_WritePin(GPIOA, RS, GPIO_Pin_Reset);
	MCAL_GPIO_WritePin(GPIOA, RW, GPIO_Pin_Reset);


}

void LCD_CMD(unsigned char cmd)
{

	//LCD_DATA = cmd;
	MCAL_GPIO_WritePort(GPIOA, cmd);
	//1-Initialize reset with 0
	MCAL_GPIO_WritePin(GPIOA, RS, GPIO_Pin_Reset);
	//2-Initialize RW with 0
	MCAL_GPIO_WritePin(GPIOA, RW, GPIO_Pin_Reset);
	MCAL_GPIO_WritePin(GPIOA, ENABLE, GPIO_Pin_SET);
	_delay_ms(2);
	MCAL_GPIO_WritePin(GPIOA, ENABLE, GPIO_Pin_Reset);


}

void change_to_output(void)

{
	PinCfg.GPIO_Pin_Number =GPIO_PIN_0 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);

	PinCfg.GPIO_Pin_Number =GPIO_PIN_1 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_2 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_3 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_4 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_5 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_6 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_7 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
}
void change_to_input(void)
{
	PinCfg.GPIO_Pin_Number =GPIO_PIN_0 ;
	PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_1 ;
	PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_2 ;
	PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_3 ;
	PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_4 ;
	PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_5 ;
	PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_6 ;
	PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_7 ;
	PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode ;
	MCAL_GPIO_init(GPIOA, &PinCfg);
}
void LCD_init(void)
{
	_delay_ms(20);
	gpio_init();
	//wait for more than 15ms after VCC reaches 4.5V
	_delay_ms(20);
	clear_screen();
	//Initiallize the LCD as 16*2 LCD 8 bit mode
	LCD_CMD(LCD_FUNCTION_8BIT_2LINES);
	_delay_ms(1);
	//make increment in the cursor
	LCD_CMD(LCD_ENTRY_MODE);
	_delay_ms(1);
	//Go to the first line
	LCD_CMD(LCD_BEGIN_AT_FIRST_ROW);
	_delay_ms(1);
	LCD_CMD(LCD_DISP_ON_CURSOR_BLINK);

}

void LCD_Write(unsigned char Data)
{
	is_busy();
	//Loading the data to PortA
	MCAL_GPIO_WritePort(GPIOA, Data);
	//	 // Reset = 1 means that it's Data if it's zero means that it's an address
	MCAL_GPIO_WritePin(GPIOA, RS, GPIO_Pin_SET);
	//Clearing the RW
	MCAL_GPIO_WritePin(GPIOA, RW, GPIO_Pin_Reset);
	_delay_ms(1);
	LCD_Enable_Function();

}

void is_busy(void)
{
	//setting the PORT A as input
	change_to_input();
	//	 //Put the LCD in read mode (RW on)
	MCAL_GPIO_WritePin(GPIOA, RW, GPIO_Pin_SET);
	//	 //put the LCD in command mode (RS off)
	MCAL_GPIO_WritePin(GPIOA, RS, GPIO_Pin_Reset);
	//Enable function
	LCD_Enable_Function();
	//setting PORT A as output
	change_to_output();
	//Disable read mode
	MCAL_GPIO_WritePin(GPIOA, RW, GPIO_Pin_Reset);

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
