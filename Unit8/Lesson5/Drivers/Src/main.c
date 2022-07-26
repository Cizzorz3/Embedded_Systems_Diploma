/*
 *  Author : Mohamed Adel
 *
 *
 *************************
 * Driver to test the UART driver for stm32f103c6
 *
 * */

#include "Keypad_Driver.h"
#include "LCD.h"
#include "Seven_Segment.h"
#include "STM32f103C6.h"
#include "STM_F103C6_GPIO_Driver.h"
#include "STM_F103C6_EXTI_Driver.h"
#include "STM32_F103_C6_USART.h"
#include "STM32_F103_C6_SPI.h"

//To choose the mode
//#define MCU_Act_As_Slave
#define MCU_Act_As_Master
unsigned int IRQ_Flag = 0;
unsigned char key ;

void EXTI9_callback(void)
{
	IRQ_Flag = 1;
	Send_string("IRQ EXTI9 has happened");
	_delay_ms(1000);

}

void SPI_IRQ_CallBack(struct S_IRQ_SRC irq){

	if(irq.RXNE){
		key = 0x0f;
		MCAL_SPI_send_and_recieve_data(SPI1, &key, disable);
		MCAL_UART_Send_Data(USART1, &key,enable);
	}


}
void UART_IRQ_Callback(void)
{
	MCAL_UART_Recieve_Data(USART1, &key, disable);
	MCAL_UART_Send_Data(USART1, &key, enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	MCAL_SPI_send_and_recieve_data(SPI1, &key, enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);

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
	UART_config uartcnfg;
	clock_init();
	uartcnfg.BaudRate = UART_Baudrate_115200;
	uartcnfg.HW_flow_control = HW_flwctl_None;
	uartcnfg.IRQ_Enable = UART_IRQ_Enable_RXE;
	uartcnfg.P_IRQ_Callback = UART_IRQ_Callback;
	uartcnfg.Parity = UART_Parity_None;
	uartcnfg.Payload_length = Payload_length_8;
	uartcnfg.stop_bits	= stop_bits_1;
	uartcnfg.USART_Mode = UART_Mode_Tx_RX;
	MCAL_UART_Init(USART1, &uartcnfg);
	MCAL_UART_Set_GPIO_Pins(USART1);

	GPIO_Pinconfig_t PinCfg;
	SPI_Config SP1CFG;
	SP1CFG.Clk_Phase = SPI_clk_phase_second_edge;
	SP1CFG.Clk_Polarity = SPI_clk_High_idle;
	SP1CFG.Data_Size = SPI_Data_size_8bit;
	SP1CFG.SPI_Prescaler = SPI_baudrate_prescaler_8;


#ifdef MCU_Act_As_Master
	SP1CFG.Device_Mode = SPI_Device_Mode_Master;
	SP1CFG.IRQ_Enable = SPI_IRQ_Enable_None;
	SP1CFG.NSS = SPI_NSS_Software_Internalsoft_set;
	SP1CFG.P_IRQ_Callback = NULL;

#endif

#ifdef MCU_Act_As_Slave
	SP1CFG.Device_Mode = SPI_Device_Mode_Slave;
		SP1CFG.IRQ_Enable = SPI_IRQ_Enable_RXNE;
		SP1CFG.NSS = SPI_NSS_Hardware_slave;
		SP1CFG.P_IRQ_Callback = NULL;

#endif
	MCAL_SPI_Init(SPI1, &SP1CFG);
	MCAL_SPI_GPIO_set_pins(SPI1);
	PinCfg.GPIO_Pin_Number = GPIO_PIN_4;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode;
	PinCfg.GPIO_Pin_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_init(GPIOA, &PinCfg);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	    while (1)
	    {

	    }
}
