/*
 * GccApplication1.c
 *
 * Created: 8/17/2022 2:24:13 AM
 * Author : Mohamed Adel
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define LED_DIR		DDRC
#define LED_PORT	PORTC
#define LED_PIN		0

#define Read_Bit(reg,bit) ((reg>>bit)&1)
#define Set_Bit(reg,bit) (reg |= (1<<bit))
#define Clear_Bit(reg,bit) (reg &=~ (1<<bit))
#define Toggle_Bit(reg,bit) (reg ^= (1<<bit))
#define Read_Bit(reg,bit) ((reg>>bit)&1)
void WDT_OFF(void)
{
		WDTCR |= (1<<WDTOE) | (1<<WDE);
		WDTCR = 0x00;
	
}
void WDT_ON(void)
{
	WDTCR |= (1<<WDE) | (1<<WDP2) | (1<<WDP1);
	Clear_Bit(WDTCR,WDP0);
	
}

int main(void)
{
	Set_Bit(LED_DIR,LED_PIN);
    /* Replace with your application code */
		_delay_ms(500);
    while (1) 
    {
		WDT_ON();
		Toggle_Bit(LED_PORT,LED_PIN);
		_delay_ms(2000);
		WDT_OFF();
    }
}

