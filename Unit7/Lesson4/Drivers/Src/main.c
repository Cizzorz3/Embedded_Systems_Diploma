/*
 *  Author : Mohamed Adel
 *
 *
 *************************
 * Driver to enable the GPIOA & GPIOB with two push buttons as input connected with PA1 and PA13
 * and output on port B on PB1 and PB13 with single pressing and multipressing on the push buttons
 * and configuring the inputs as open drain inputs
 *
 * */

#include "Keypad_Driver.h"
#include "LCD.h"
#include "Seven_Segment.h"
#include "STM32f103C6.h"
#include "STM_F103C6_GPIO_Driver.h"
#include "STM_F103C6_EXTI_Driver.h"

unsigned int IRQ_Flag = 0;

void EXTI9_callback(void)
{
	IRQ_Flag = 1;
	Send_string("IRQ EXTI9 has happened");
	_delay_ms(1000);

}

void clock_init(void)
{
	//Enabling the clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	AFIO_GPIO_CLK_EN();
}
int main (void)
{
	char pressed_key ;
	clock_init();
	gpio_init();
	LCD_init();
	seven_segment_init();
	seven_segment_start();
	keypad_init();
	EXTI_PinConfig_t EXTI_CFG ;
	EXTI_CFG.EXTI_pin = EXTI9PB9;
	EXTI_CFG.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_CFG.GP_IRQ_CallBack = EXTI9_callback;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_Enable ;

	MCAL_EXTI_GPIO_init(&EXTI_CFG);
	IRQ_Flag = 1;
	    while (1)
	    {
	    	if(IRQ_Flag)
	    	{
				clear_screen();
				IRQ_Flag =0;
	    	}
	    }
}
