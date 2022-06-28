/*
 * LCD.h
 *
 * Created: 6/23/2022 9:00:26 PM
 *  Author: Mohamed Adel
 */


#ifndef LCD_H_
#define LCD_H_
#include "STM32f103C6.h"
#include "STM_F103C6_GPIO_Driver.h"

//APIS
void _delay_ms(uint32_t i);
//initializing the GPIO pins
void gpio_init(void);
//initializing the LCD
void LCD_init(void);
//Sending the commands instructions to the LCD
void LCD_CMD(unsigned char cmd);
//writing on the LCD
void LCD_Write(unsigned char Data);
//checking if the LCD is busy
void is_busy(void);
//clearing the screen
void clear_screen(void);
//sending a string to the screen
void Send_string(char * data);
//go to the next line after the first is completed
void LCD_XY(int row , int col);
//LCD Control PINS

#define LCD_DATA GPIOA
#define LCD_CTRL_PORT GPIOA
#define ENABLE GPIO_PIN_10
#define	RS GPIO_PIN_8
#define RW GPIO_PIN_9

//LCD command instructions
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)
#define LCD_Return_home								(0x02)

#endif /* LCD_H_ */
