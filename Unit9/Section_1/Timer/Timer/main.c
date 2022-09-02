/*
 * Timer.c
 *
 * Created: 8/17/2022 2:49:08 AM
 * Author : Mohamed Adel
 */ 

#include <avr/io.h>
#include "MCAL/Timer.h"

void Timer_OVF_CALLBACK()
{
	PORTA = ~PORTA;
}

int main(void)
{
	DDRA = 0xff;
	Timer0_Set_Callback_Compare_value_IR(Timer_OVF_CALLBACK);
	Timer0_config = {CTC,Prescaling_CLK8,OCIE_Enable,TOIE_Disable};
	Timer0_Set_Overflow_value(0xF0);
	Timer0_init();
    /* Replace with your application code */
    while (1) 
    {
    }
}

