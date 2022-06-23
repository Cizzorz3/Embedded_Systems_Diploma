/*
 * LED_sequentiel.c
 *
 * Created: 6/23/2022 2:28:21 AM
 * Author : Mohamed Adel
 */ 

/*
 Driver for Atmega32 to light up all the led on port d 
 sequin telly
*/

#include "Utils.h"
typedef unsigned int uint32_t ;

//Configurations
#define PORTD_Base *(volatile uint32_t *)(0x32)
#define DDRD_Base *(volatile uint32_t *)(0x31)



void gpio_init(void)
{
	DDRD_Base = 1 ;
}

void delay_ms(uint32_t x)
{
	uint32_t i , j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<255;j++);
	}
}


int main(void)
{
    gpio_init();
    while (1) 
    {
		Sit_Bit(PORTD_Base,0);
		delay_ms(10);
		Clear_Bit(PORTD_Base,0);
		Sit_Bit(PORTD_Base,1);
		delay_ms(10);
		Clear_Bit(PORTD_Base,1);
		Sit_Bit(PORTD_Base,2);
		delay_ms(10);
		Clear_Bit(PORTD_Base,2);
		Sit_Bit(PORTD_Base,3);
		delay_ms(10);
		Clear_Bit(PORTD_Base,3);
		Sit_Bit(PORTD_Base,4);
		delay_ms(10);	
		Clear_Bit(PORTD_Base,4);
		Sit_Bit(PORTD_Base,5);
		delay_ms(10);
		Clear_Bit(PORTD_Base,5);
		Sit_Bit(PORTD_Base,6);
		delay_ms(10);
		Clear_Bit(PORTD_Base,6);
		Sit_Bit(PORTD_Base,7);
		delay_ms(10);
		Clear_Bit(PORTD_Base,7);
		
    }
}

