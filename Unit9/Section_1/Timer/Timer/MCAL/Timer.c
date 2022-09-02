/*
 * Timer.c
 *
 * Created: 8/17/2022 2:53:22 AM
 *  Author: Mohamed Adel
 */ 
#include "Timer.h"
PTR_VoidFUN Callback_OVF ;
PTR_VoidFUN Callback_CM ;
Timer0_config Timer0_configurations ;
uint8_t u8_TOVNumber;
E_Status Timer0_init(Timer0_config * timer_configurations)
{
	E_Status u8_Retval = Error;
	if(NULL_PTR == timer_configurations)
	{
		u8_Retval = Error;
	}
	else
	{
		Timer0_configurations=timer_configurations ;
		if(Timer0_configurations->mode == Normal ||Timer0_configurations->mode == CTC )
		{
			TCCR0 |= Timer0_configurations.mode ;
			u8_Retval = Ok;
		}
		else
		{
			u8_Retval = Error;
		}
		if(Timer0_configurations->clk >= No_CLK_Source && Timer0_configurations->clk <=EXT_CLK_Rising)
		{
			TCCR0 |= Timer0_configurations->clk;
			u8_Retval = Ok;
			
		}
		else
		{
			u8_Retval = Error;
			
		}
		if(Timer0_configurations->OCM_interrupt == OCIE_Disable || Timer0_configurations->OCM_interrupt ==OCIE_Enable)
		{
			TIMSK |= Timer0_configurations->OCM_interrupt;
			u8_Retval = Ok;
			
		}
		else
		{
			u8_Retval = Error;
			
		}
		if(Timer0_configurations->OVF_interrupt == TOIE_Disable || Timer0_configurations->OVF_interrupt ==TOIE_Enable)
		{
			TIMSK |= Timer0_configurations->OVF_interrupt;
			u8_Retval = Ok;
			
		}
		else
		{
			u8_Retval = Error;
			
		}
		
		
	}
	return u8_Retval;
}
E_Status Timer0_stop(void)
{
	E_Status u8_Retval = Error;
	Clear_Bit(TIMSK,CS00);
	Clear_Bit(TIMSK,CS01);
	Clear_Bit(TIMSK,CS02);
	
	return u8_Retval;
}
E_Status Timer0_Get_Compare_value(P_uint8_t  pu8_ticks)
{	
	E_Status u8_Retval = Error;
	*pu8_ticks = OCR0;
	return u8_Retval;
	
}
E_Status Timer0_Set_Compare_value(uint8_t  u8_Ticks)
{
	E_Status u8_Retval = Error;
	OCR0  = u8_Ticks ;
	return u8_Retval;
}
E_Status Timer0_Get_Counter_value(P_uint8_t  pu8_ticks)
{
	E_Status u8_Retval = Error;
	*pu8_ticks  = TCNT0 ;
	return u8_Retval;
}
E_Status Timer0_Set_Counter_value(uint8_t  u8_Ticks)
{
	E_Status u8_Retval = Error;
	TCNT0  = u8_Ticks ;
	return u8_Retval;
}
E_Status Timer0_Get_Overflow_value(P_uint8_t  pu8_ticks)
{
	E_Status u8_Retval = Error;
	*pu8_ticks = u8_TOVNumber;
	return u8_Retval;
}
E_Status Timer0_Set_Overflow_value(uint8_t  u8_Ticks)
{
	E_Status u8_Retval = Error;
	u8_TOVNumber = u8_Ticks
	return u8_Retval;
}

void Timer0_Set_Callback_OVF_IR(PTR_VoidFUN * callback)
{
	Callback_OVF = callback;
}
void Timer0_Set_Callback_Compare_value_IR(PTR_VoidFUN * callback)
{
	Callback_CM = callback;
}

ISR(TIMER0_COMP_vect)
{
	Callback_CM();
}
ISR(TIMER0_OVF_vect)
{
	u8_TOVNumber++;
	Callback_OVF();
}