/*
 * Timer.h
 *
 * Created: 8/17/2022 2:53:03 AM
 *  Author: Mohamed Adel
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Utils.h"

typedef enum 
{
	Normal,
	CTC = 0x08
		
}TIMER0_Mode_t;

typedef enum
{
	
	No_CLK_Source,
	No_Prescaling,
	Prescaling_CLK8,
	Prescaling_CLK64,
	Prescaling_CLK256,
	Prescaling_CLK1024,
	EXT_CLK_Falling,
	EXT_CLK_Rising
	
}TIMER0_Clock_t;

typedef enum
{
	OCIE_Disable,
	OCIE_Enable = 0x02
	
}OCMIE0_t;
typedef enum
{
	TOIE_Disable,
	TOIE_Enable = 0x01
}TOVFIE0_t;


typedef struct
{
	TIMER0_Mode_t mode ;
	TIMER0_Clock_t clk;
	OCMIE0_t OCM_interrupt;
	TOVFIE0_t OVF_interrupt;
}Timer0_config;


E_Status Timer0_init(Timer0_config * timer_configurations);
E_Status Timer0_stop(void);
E_Status Timer0_Get_Compare_value(P_uint8_t * pu8_ticks);
E_Status Timer0_Set_Compare_value(uint8_t * u8_Ticks);
E_Status Timer0_Get_Counter_value(P_uint8_t * pu8_ticks);
E_Status Timer0_Set_Counter_value(uint8_t * u8_Ticks);
E_Status Timer0_Get_Overflow_value(P_uint8_t * pu8_ticks);
E_Status Timer0_Set_Overflow_value(uint8_t * u8_Ticks);

void Timer0_Set_Callback_OVF_IR(PTR_VoidFUN * callback);
void Timer0_Set_Callback_Compare_value_IR(PTR_VoidFUN * callback);
#endif /* TIMER_H_ */

