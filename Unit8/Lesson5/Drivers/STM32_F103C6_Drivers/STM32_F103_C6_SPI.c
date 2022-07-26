/*
 * STM32_F103_C6_SPI.c
 *
 *  Created on: Jul 25, 2022
 *      Author: Mohamed Adel
 *
 *
 */

#include "inc/STM32_F103_C6_SPI.h"

SPI_Config* Global_SPI_Config[2] = {NULL,NULL};

#define SPI1_Index		0
#define SPI2_Index		1


#define SPI_SR_TXE		((uint8_t)0x02) // transmit empty
#define	SPI_SR_RXNE		((uint8_t)0x01)	//rx empty
//Generic vaiables

//APIS

void MCAL_SPI_Init(SPI_typedef *SPIx , SPI_Config* SPI_Config)
{
	//safety for reigsters
	uint16_t temp_CR1=0;
	uint16_t temp_CR2=0;
	if(SPIx==SPI1)
	{
		Global_SPI_Config[SPI1_Index]=SPI_Config;
		RCC_SPI1_CLK_EN();

	}
	else if (SPIx==SPI2)
	{
		Global_SPI_Config[SPI2_Index]=SPI_Config;
		RCC_SPI2_CLK_EN();

	}
	//1-Enable SPI CR1 bit : 6
	temp_CR1 = (0x1U)<<6;
	temp_CR1 |= SPI_Config->Device_Mode;

	//2-SPI communication mode
	temp_CR1 |= SPI_Config->Communication_Mode;

	//3-SPI frame format
	temp_CR1 |= SPI_Config->Frame_Format;

	//4-clock polarity
	temp_CR1 |= SPI_Config->Clk_Polarity;

	//5-data size
	temp_CR1 |= SPI_Config->Data_Size;

	//6-clock phase
	temp_CR1 |= SPI_Config->Clk_Phase;

	//7-NSS
	if(SPI_Config->NSS == SPI_NSS_Hardware_Master_output_enable)
	{
		temp_CR2 |= SPI_Config->NSS;
	}
	else if (SPI_Config->NSS == SPI_NSS_Hardware_Master_output_disable)
	{
		temp_CR2 &= SPI_Config->NSS;

	}
	else
	{
		temp_CR1 |=SPI_Config->NSS;;
	}

	//8-baud rate
	temp_CR1 |= SPI_Config->SPI_Prescaler;


	//9-IRQ
	if(SPI_Config->IRQ_Enable |= SPI_IRQ_Enable_None)
	{
		temp_CR2 |= SPI_Config->IRQ_Enable;

		if(SPIx==SPI1)
		{
			NVIC_IRQ35_SPI1_Enable;
		}
		else if (SPIx==SPI2)
		{
			NVIC_IRQ36_SPI2_Enable;
		}
	}

	SPIx->CR1 = temp_CR1;
	SPIx->CR2 = temp_CR2;
}
void MCAL_SPI_DeInit(SPI_typedef *SPIx)
{
	if(SPIx==SPI1)
	{
		NVIC_IRQ35_SPI1_Disable;
		RCC_SPI1_CLK_Reset();
	}
	else if (SPIx==SPI2)
	{
		NVIC_IRQ36_SPI2_Disable;
		RCC_SPI2_CLK_Reset();

	}
}
void MCAL_SPI_GPIO_set_pins(SPI_typedef *SPIx)
{
	GPIO_Pinconfig_t PinCfg;
	if(SPIx==SPI1)
	{
		if(Global_SPI_Config[SPI1_Index]->Device_Mode ==SPI_Device_Mode_Master) //Master
		{
			switch(Global_SPI_Config[SPI1_Index]->NSS)
			{
			case SPI_NSS_Hardware_Master_output_disable :
				PinCfg.GPIO_Pin_Number = GPIO_PIN_4;
				PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
				MCAL_GPIO_init(GPIOA, &PinCfg);
				break;
			case SPI_NSS_Hardware_Master_output_enable :
				PinCfg.GPIO_Pin_Number = GPIO_PIN_4;
				PinCfg.GPIO_Pin_Mode = GPIO_AF_output_Push_pull_Mode;
				PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M;
				MCAL_GPIO_init(GPIOA, &PinCfg);
				break;
			}
			PinCfg.GPIO_Pin_Number = GPIO_PIN_5;
			PinCfg.GPIO_Pin_Mode = GPIO_AF_output_Push_pull_Mode;
			PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &PinCfg);

			PinCfg.GPIO_Pin_Number = GPIO_PIN_6;
			PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
			PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &PinCfg);

			PinCfg.GPIO_Pin_Number = GPIO_PIN_7;
			PinCfg.GPIO_Pin_Mode = GPIO_AF_output_Push_pull_Mode;
			PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &PinCfg);
		}
		else //slave
		{
			if(Global_SPI_Config[SPI1_Index]->Device_Mode ==SPI_NSS_Hardware_slave)
			{
				PinCfg.GPIO_Pin_Number = GPIO_PIN_4;
				PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
				MCAL_GPIO_init(GPIOA, &PinCfg);
			}
			PinCfg.GPIO_Pin_Number = GPIO_PIN_5;
			PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
			MCAL_GPIO_init(GPIOA, &PinCfg);

			PinCfg.GPIO_Pin_Number = GPIO_PIN_6;
			PinCfg.GPIO_Pin_Mode = GPIO_AF_output_Push_pull_Mode;
			PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &PinCfg);

			PinCfg.GPIO_Pin_Number = GPIO_PIN_7;
			PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
			MCAL_GPIO_init(GPIOA, &PinCfg);
		}
	}
	else if (SPIx==SPI2)
	{
		if(Global_SPI_Config[SPI2_Index]->Device_Mode ==SPI_Device_Mode_Master) //Master
				{
					switch(Global_SPI_Config[SPI2_Index]->NSS)
					{
					case SPI_NSS_Hardware_Master_output_disable :
						PinCfg.GPIO_Pin_Number = GPIO_PIN_12;
						PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
						MCAL_GPIO_init(GPIOA, &PinCfg);
						break;
					case SPI_NSS_Hardware_Master_output_enable :
						PinCfg.GPIO_Pin_Number = GPIO_PIN_12;
						PinCfg.GPIO_Pin_Mode = GPIO_AF_output_Push_pull_Mode;
						PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M;
						MCAL_GPIO_init(GPIOA, &PinCfg);
						break;
					}
					PinCfg.GPIO_Pin_Number = GPIO_PIN_13;
					PinCfg.GPIO_Pin_Mode = GPIO_AF_output_Push_pull_Mode;
					PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M;
					MCAL_GPIO_init(GPIOA, &PinCfg);

					PinCfg.GPIO_Pin_Number = GPIO_PIN_14;
					PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
					PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M;
					MCAL_GPIO_init(GPIOA, &PinCfg);

					PinCfg.GPIO_Pin_Number = GPIO_PIN_15;
					PinCfg.GPIO_Pin_Mode = GPIO_AF_output_Push_pull_Mode;
					PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M;
					MCAL_GPIO_init(GPIOA, &PinCfg);
				}
				else //slave
				{
					if(Global_SPI_Config[SPI2_Index]->Device_Mode ==SPI_NSS_Hardware_slave)
					{
						PinCfg.GPIO_Pin_Number = GPIO_PIN_12;
						PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
						MCAL_GPIO_init(GPIOA, &PinCfg);
					}
					PinCfg.GPIO_Pin_Number = GPIO_PIN_13;
					PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
					MCAL_GPIO_init(GPIOA, &PinCfg);

					PinCfg.GPIO_Pin_Number = GPIO_PIN_14;
					PinCfg.GPIO_Pin_Mode = GPIO_AF_output_Push_pull_Mode;
					PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M;
					MCAL_GPIO_init(GPIOA, &PinCfg);

					PinCfg.GPIO_Pin_Number = GPIO_PIN_15;
					PinCfg.GPIO_Pin_Mode = GPIO_Floating_input_Mode;
					MCAL_GPIO_init(GPIOA, &PinCfg);
				}
	}
}
void MCAL_SPI_send_data(SPI_typedef *SPIx , uint16_t *pTx_buffer , enum Polling_mechanism Polling_en)
{
	if(Polling_en == Polling_en)
		while(!((SPIx)->SR & SPI_SR_TXE));
	SPIx->DR = *pTx_buffer;
}
void MCAL_SPI_recieve_data(SPI_typedef *SPIx , uint16_t *pRx_buffer , enum Polling_mechanism Polling_en)
{
	if(Polling_en == Polling_en)
			while(!((SPIx)->SR & SPI_SR_RXNE));
		 *pRx_buffer = SPIx->DR;
}
void MCAL_SPI_send_and_recieve_data(SPI_typedef *SPIx , uint16_t *pTx_buffer , enum Polling_mechanism Polling_en)
{
	if(Polling_en == Polling_en)
			while(!((SPIx)->SR & SPI_SR_TXE));
	SPIx->DR = *pTx_buffer;
	if(Polling_en == Polling_en)
		while(!((SPIx)->SR & SPI_SR_RXNE));
	*pTx_buffer = SPIx->DR;
}


//IRQ
void SPI1_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src ;
	irq_src.TXE = ((SPI1->SR & (1<<1))>>1);
	irq_src.RXNE = ((SPI1->SR & (1<<0))>>0);
	irq_src.ERRI = ((SPI1->SR & (1<<4))>>4);

	Global_SPI_Config[SPI1_Index]->P_IRQ_Callback(irq_src);
}
void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src ;
	irq_src.TXE = ((SPI2->SR & (1<<1))>>1);
	irq_src.RXNE = ((SPI2->SR & (1<<0))>>0);
	irq_src.ERRI = ((SPI2->SR & (1<<4))>>4);

		Global_SPI_Config[SPI2_Index]->P_IRQ_Callback(irq_src);
}
