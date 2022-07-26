/*
 * STM32_F103_C6_EXTI.c
 *
 *  Created on: Jun 28, 2022
 *      Author: Mohamed Adel
 */


#include "STM_F103C6_EXTI_Driver.h"
#include "STM_F103C6_GPIO_Driver.h"


//=============================================================================
//					Generic variables
//=============================================================================
	void (*GP_IRQ_CallBack[15])(void);

//==============================================================================
//					Generic Macros
//==============================================================================
#define AFIO_GPIO_EXTI_Mapping(x)			( (x==GPIOA)?0:\
											  	  (x==GPIOB)?1:\
											  	  (x==GPIOC)?2:\
											  	   (x==GPIOD)?3:0 )
//================================================================================
//					Generic functions
//================================================================================
void Enable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0 :
		NVIC_IRQ6_EXTI0_Enable ;
		break;
	case 1 :
			NVIC_IRQ7_EXTI1_Enable ;
			break;
	case 2 :
			NVIC_IRQ8_EXTI2_Enable ;
			break;
	case 3 :
			NVIC_IRQ9_EXTI3_Enable ;
			break;
	case 4 :
			NVIC_IRQ10_EXTI4_Enable ;
			break;
	case 5 :
	case 6 :
	case 7 :
	case 8 :
	case 9 :
		NVIC_IRQ23_EXTI5_9_Enable ;
		break;
	case 10 :
	case 11 :
	case 12 :
	case 13 :
	case 14 :
	case 15 :
		NVIC_IRQ40_EXTI10_15_Enable;
		break ;
	}
}
void Disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
		{
		case 0 :
			NVIC_IRQ6_EXTI0_Disable ;
			break;
		case 1 :
				NVIC_IRQ7_EXTI1_Disable ;
				break;
		case 2 :
				NVIC_IRQ8_EXTI2_Disable ;
				break;
		case 3 :
				NVIC_IRQ9_EXTI3_Disable ;
				break;
		case 4 :
				NVIC_IRQ10_EXTI4_Disable ;
				break;
		case 5 :
		case 6 :
		case 7 :
		case 8 :
		case 9 :
			NVIC_IRQ23_EXTI5_9_Disable ;
			break;
		case 10 :
		case 11 :
		case 12 :
		case 13 :
		case 14 :
		case 15 :
			NVIC_IRQ40_EXTI10_15_Disable;
			break ;
		}
}


//================================================================================


void Update_EXTI(EXTI_PinConfig_t * EXTI_Config)
{
	//1- configure GPIO to be AF input -> Floating input
	GPIO_Pinconfig_t PinCfg ;
	PinCfg.GPIO_Pin_Number = EXTI_Config->EXTI_pin.GPIO_Pin ;
	PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
	MCAL_GPIO_init(EXTI_Config->EXTI_pin.GPIO_Port, &PinCfg);

	//2-Update AFIO to Route between EXTI with PORT A,B,C or D
	uint8_t AFIO_EXTICR_index=EXTI_Config->EXTI_pin.EXT_Input_line_Number/4;

	//position
	uint8_t AFIO_EXTICR_postion = (EXTI_Config->EXTI_pin.EXT_Input_line_Number%4)*4;

	//clear the four bit first
	AFIO->EXTICR[AFIO_EXTICR_index] &=~(0xF<<AFIO_EXTICR_postion);
	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_pin.GPIO_Port)&0xF) <<AFIO_EXTICR_postion);

	//update rising and falling edge
	EXTI->RTSR &=~ (1<<EXTI_Config->EXTI_pin.EXT_Input_line_Number);
	EXTI->FTSR &=~ (1<<EXTI_Config->EXTI_pin.EXT_Input_line_Number);

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_Rising)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_pin.EXT_Input_line_Number);

	}
	else if (EXTI_Config->Trigger_Case == EXTI_Trigger_Falling)
	{
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_pin.EXT_Input_line_Number);

	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_RisingAndFalling)
	{
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_pin.EXT_Input_line_Number);
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_pin.EXT_Input_line_Number);

	}

	//update IRQ Handling callback
	GP_IRQ_CallBack[EXTI_Config->EXTI_pin.EXT_Input_line_Number] = EXTI_Config->GP_IRQ_CallBack;

	//enable/disable IRQ
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |=(1<<EXTI_Config->EXTI_pin.EXT_Input_line_Number);
		Enable_NVIC (EXTI_Config->EXTI_pin.EXT_Input_line_Number);
	}


}
/**================================================================
 * @Fn				- MCAL_EXTI_GPIO_init
 * @brief 			- Initializes the EXTI  peripheral according to the EXTI config
 * @param [in]		- EXTI_Config which contains the pin number , port number , Rising case and Mask enable
 * @param [in]
 * @retval 			- None
 * Note				- STM32F103C6 MCU  has GPIO A,B,C,D,E
 * 					- But package LQF48 has only GPIO A,B and part of C/D
 */
void MCAL_EXTI_GPIO_init(EXTI_PinConfig_t *EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}
/**================================================================
 * @Fn				- MCAL_EXTI_GPIO_DeInit
 * @brief 			- DeInitializes the EXTI  peripheral according to the EXTI config
 * @param [in]
 * @param [in]
 * @retval 			- None
 * Note				- STM32F103C6 MCU  has GPIO A,B,C,D,E
 * 					- But package LQF48 has only GPIO A,B and part of C/D
 */
void MCAL_EXTI_GPIO_DeInit(void)
{
	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;

	//write 1 to clear
	EXTI->PR = 0xffffffff;

	//Disable EXTI from NVIC
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;
}
/**================================================================
 * @Fn				- MCAL_EXTI_GPIO_init
 * @brief 			- Updates the EXTI  peripheral according to the EXTI config
 * @param [in]		- EXTI_Config which contains the pin number , port number , Rising case and Mask enable
 * @param [in]
 * @retval 			- None
 * Note				- STM32F103C6 MCU  has GPIO A,B,C,D,E
 * 					- But package LQF48 has only GPIO A,B and part of C/D
 */
void MCAL_EXTI_Update(EXTI_PinConfig_t *EXTI_Config)
{
	Update_EXTI(EXTI_Config);

}


//================================================================================
//						ISR Functions
//================================================================================
void EXTI0_IRQHandler(void)
{
	//clear by writing 1 to pending register
	EXTI->PR |= 1<<0;

	//call IRQ
	GP_IRQ_CallBack[0]();
}
void EXTI1_IRQHandler(void)
{
	//clear by writing 1 to pending register
	EXTI->PR |= 1<<0;

	//call IRQ
	GP_IRQ_CallBack[0]();
}

void EXTI2_IRQHandler(void)
{
	//clear by writing 1 to pending register
	EXTI->PR |= 1<<1;

	//call IRQ
	GP_IRQ_CallBack[1]();
}

void EXTI3_IRQHandler(void)
{
	//clear by writing 1 to pending register
	EXTI->PR |= 1<<2;

	//call IRQ
	GP_IRQ_CallBack[2]();
}

void EXTI4_IRQHandler(void)
{
	//clear by writing 1 to pending register
	EXTI->PR |= 1<<3;

	//call IRQ
	GP_IRQ_CallBack[3]();
}

void EXTI9_5_IRQHandler(void)
{
	if (EXTI->PR & 1<<5) {EXTI->PR |= (1<<5) ; GP_IRQ_CallBack[5]();}
	if (EXTI->PR & 1<<6) {EXTI->PR |= (1<<6) ; GP_IRQ_CallBack[6]();}
	if (EXTI->PR & 1<<7) {EXTI->PR |= (1<<7) ; GP_IRQ_CallBack[7]();}
	if (EXTI->PR & 1<<8) {EXTI->PR |= (1<<8) ; GP_IRQ_CallBack[8]();}
	if (EXTI->PR & 1<<9) {EXTI->PR |= (1<<9) ; GP_IRQ_CallBack[9]();}
}
void EXTI15_10_IRQHandler(void)
{
	if (EXTI->PR & 1<<10) {EXTI->PR |= (1<<10) ; GP_IRQ_CallBack[10]();}
	if (EXTI->PR & 1<<11) {EXTI->PR |= (1<<11) ; GP_IRQ_CallBack[11]();}
	if (EXTI->PR & 1<<12) {EXTI->PR |= (1<<12) ; GP_IRQ_CallBack[12]();}
	if (EXTI->PR & 1<<13) {EXTI->PR |= (1<<13) ; GP_IRQ_CallBack[13]();}
	if (EXTI->PR & 1<<14) {EXTI->PR |= (1<<14) ; GP_IRQ_CallBack[14]();}
	if (EXTI->PR & 1<<15) {EXTI->PR |= (1<<15) ; GP_IRQ_CallBack[15]();}

}


