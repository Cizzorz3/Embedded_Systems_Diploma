/*
 * STM32_F103_C6_SPI.h
 *
 *  Created on: Jul 25, 2022
 *      Author: Mohamed Adel
 */

#ifndef INC_STM32_F103_C6_SPI_H_
#define INC_STM32_F103_C6_SPI_H_

#include "STM32f103C6.h"
#include "STM_F103C6_GPIO_Driver.h"

struct S_IRQ_SRC
{
	uint8_t TXE:1;		//Tx buffer empty IRQ
	uint8_t RXNE:1;		//Rx buffer empty IRQ
	uint8_t ERRI:1;		//Error irq
	uint8_t Reserverd:5;
};

//configuration structure
typedef struct
{
	uint16_t Device_Mode ; //Specify the spi opearting mode (Master/Slave)
	uint16_t Communication_Mode ; //Specify the spi bidirectional mode state
	uint16_t Frame_Format ; // Specify the spi LSB or MSB
	uint16_t Data_Size ; // Specify the spi Datasize
	uint16_t Clk_Polarity ; //Specify the spi Clk_Polarity
	uint16_t Clk_Phase ; //Specify the spi Phase
	uint16_t NSS ;//Specify the spi NSS signal is managed by Hardware (NSS pin) or by software
	uint16_t SPI_Prescaler ; //Specify the baudrate prescaler
	uint16_t IRQ_Enable ; // To enable spi irq

	void (*P_IRQ_Callback)(struct S_IRQ_SRC); // IRQ c function which starts when the irq occurs
}SPI_Config;



//Refrence macros


//SPI deveice mode
#define SPI_Device_Mode_slave			(0x00000000U)
#define SPI_Device_Mode_Master			(0x1U<<2) //CR1 MSTR :1 Master Mode

//SPI communication mode
#define SPI_direction_2Lines 				(0x00000000U)
#define SPI_direction_2lines_RX_only		(0x1U<<10)	//CR1 bit 10 RX only recieve only
#define SPI_direction_1line_Recieve_only	(0x1U<<15)	//CR1 bit 15 Bidirectional data mode enable
#define SPI_direction_1line_transmit_only	(0x1U<<15) | (0x1U<<14) //CR1 bit 15 Bidirectional data mode enable & bit 14 for transmit


//SPI_Data_Size
#define SPI_Data_size_8bit				(0x00000000U)
#define SPI_Data_size_16bit				(0x1U<<11)


//SPI Data format
#define SPI_MSB_first					(0x00000000U)
#define SPI_LSB_first					(0x1U<<7)


//SPI clk polarity
#define SPI_clk_low_idle				(0x00000000U)
#define SPI_clk_High_idle				(0x1U<<1)


//SPI clk phase
#define SPI_clk_phase_first_edge		(0x00000000U)
#define SPI_clk_phase_second_edge		(0x1U<<0)


//NSS
//Hardware
#define SPI_NSS_Hardware_slave						(0x00000000U)
#define SPI_NSS_Hardware_Master_output_enable		(0x1U<<2)
#define SPI_NSS_Hardware_Master_output_disable		~(0x1U<<2)

//SW
#define SPI_NSS_Software_Internalsoft_Reset			(0x1U<<9)
#define SPI_NSS_Software_Internalsoft_set			(0x1U<<9) | (0x1U<<8)


//baudrate
#define SPI_baudrate_prescaler_2						(0x00000000U)
#define SPI_baudrate_prescaler_4						(0b001U<<3)
#define SPI_baudrate_prescaler_8						(0b010U<<3)
#define SPI_baudrate_prescaler_16						(0b011U<<3)
#define SPI_baudrate_prescaler_32						(0b100U<<3)
#define SPI_baudrate_prescaler_64						(0b101U<<3)
#define SPI_baudrate_prescaler_128						(0b110U<<3)
#define SPI_baudrate_prescaler_256						(0b111U<<3)


//spi_irq_enable
#define SPI_IRQ_Enable_None								(uint32_t)(0)
#define SPI_IRQ_Enable_TEXIE							(uint32_t)(1<<7)
#define SPI_IRQ_Enable_RXNEIE							(uint32_t)(1<<6)
#define SPI_IRQ_Enable_ERRIE							(uint32_t)(1<<5)





//APIS

void MCAL_SPI_Init(SPI_typedef *SPIx , SPI_Config* SPI_Config);
void MCAL_SPI_DeInit(SPI_typedef *SPIx);
void MCAL_SPI_GPIO_set_pins(SPI_typedef *SPIx);
void MCAL_SPI_send_data(SPI_typedef *SPIx , uint16_t *pTx_buffer , enum Polling_mechanism Polling_en);
void MCAL_SPI_recieve_data(SPI_typedef *SPIx , uint16_t *pRx_buffer , enum Polling_mechanism Polling_en);
void MCAL_SPI_send_and_recieve_data(SPI_typedef *SPIx , uint16_t *pTx_buffer , enum Polling_mechanism Polling_en);
#endif /* INC_STM32_F103_C6_SPI_H_ */
