/*
 * ADC.c
 *
 * Created: 9/2/2022 11:09:19 AM
 * Author : Mohamed Adel
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL

#include <util/delay.h>
#include "LCD/LCD.h"
#include "ADC_Driver/ADC.h"
int main(void)
{
	int ADC_val;
	Clear_Bit(DDRA,PA0);
	LCD_INIT();
	ADC_init(VCC_EXT_Cap,ADC0,Prescaler_64);
    /* Replace with your application code */
	LCD_GOTO_XY(0,0);
	LCD_WRITE_STRING("ADC");
	LCD_GOTO_XY(1,0);
    while (1) 
    {
		ADC_val=ADC_read();
		LCD_WRITE_STRING("              ");
		LCD_GOTO_XY(2,0);
		LCD_IntegerToString(ADC_val);
		_delay_ms(1000);
		
	
		//LCD_IntegerToString(ADC_val);
		
		
		
		
    }
}	

