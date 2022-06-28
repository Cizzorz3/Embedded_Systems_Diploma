/*
 * Seven_segment.c
 *
 *  Created on: Jun 27, 2022
 *      Author: Mohamed Adel
 */


#include "Seven_Segment.h"
#include "STM32f103C6.h"
#include "STM_F103C6_GPIO_Driver.h"



void seven_segment_init(void)
{
	GPIO_Pinconfig_t PinCfg ;
	PinCfg.GPIO_Pin_Number =GPIO_PIN_9 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_10 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_11 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_12 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_13 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_14 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);
	PinCfg.GPIO_Pin_Number =GPIO_PIN_15 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);
}
void seven_segment_start(void)
{
	unsigned char seg[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	unsigned char lcd[] = {'0','1','2','3','4','5','6','7','8','9'};


	for(unsigned char i=0;i<11;i++)
	{
		MCAL_GPIO_WritePort(GPIOB, seg[i]<<9);
		LCD_Write(lcd[i]);
		_delay_ms(30);
	}
	clear_screen();
}

