/*
 * Seven_Segment.c
 *
 * Created: 6/23/2022 3:02:10 AM
 * Author : Mohamed Adel
 */ 

#include "Utils.h"
typedef unsigned int uint32_t;
#define PORTC_Base *(volatile uint32_t *)(0x35)
#define DDRC_Base *(volatile uint32_t *)(0x34)


char segment[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	
#define F_CPU 16000000UL
void gpio_init(void)
{
	DDRC_Base = 1 ;	
	PORTC_Base =  0;
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
	unsigned char flag1 , flag2 ;
    gpio_init();
    while (1) 
    {
			for(flag1=0 ; flag1 <=9 ; flag1++)
			{
				for(flag2=0;flag2<=9;flag2++)
				{
					Sit_Bit(PORTC_Base,2);
					Clear_Bit(PORTC_Base,3);
					PORTC_Base = segment[flag1];
					delay_ms(60);
					Sit_Bit(PORTC_Base,3);
					Clear_Bit(PORTC_Base,2);
					PORTC_Base = segment[flag2];
					delay_ms(60);	   				
				}
				
			}			
    }
}

