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

#include "STM32f103C6.h"
#include "STM_F103C6_GPIO_Driver.h"

void gpio_init()
{
	GPIO_Pinconfig_t Pincfg ;
	Pincfg.GPIO_Pin_Number =GPIO_PIN_1 ;
	Pincfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode ;
	MCAL_GPIO_init(GPIOA, &Pincfg);


	Pincfg.GPIO_Pin_Number =GPIO_PIN_1 ;
	Pincfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	Pincfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &Pincfg);

	Pincfg.GPIO_Pin_Number =GPIO_PIN_13 ;
	Pincfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode ;
	MCAL_GPIO_init(GPIOA, &Pincfg);

	Pincfg.GPIO_Pin_Number =GPIO_PIN_13 ;
	Pincfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	Pincfg.GPIO_Pin_Speed  =GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &Pincfg);

}
void clock_init(void)
{
	//Enabling the clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

void delay_ms(unsigned int p)
{
	//delay function
	uint32_t i ,j;
	for(i=0;i<p;i++ ){
		for(j=0;j<255;j++);
	}
}
int main (void)
{
	clock_init();
	gpio_init();

	while(1)
	{
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0);
		}
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1)
		{
				MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
				delay_ms(100);
		}


	}
}
