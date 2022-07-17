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
	UART_config uartcnfg;
	unsigned char key ;
	clock_init();
	uartcnfg.BaudRate = UART_Baudrate_115200;
	uartcnfg.HW_flow_control = HW_flwctl_None;
	uartcnfg.IRQ_Enable = UART_IRQ_Enable_None;
	uartcnfg.P_IRQ_Callback = NULL;
	uartcnfg.Parity = UART_Parity_None;
	uartcnfg.Payload_length = Payload_length_8;
	uartcnfg.stop_bits	= stop_bits_1;
	uartcnfg.USART_Mode = UART_Mode_Tx_RX;
	MCAL_UART_Init(USART1, &uartcnfg);
	MCAL_UART_Set_GPIO_Pins(USART1);

	    while (1)
	    {
	    	MCAL_UART_Recieve_Data(USART1, &key, enable);
	    	MCAL_UART_Send_Data(USART1, &key, enable);
	    }
}
