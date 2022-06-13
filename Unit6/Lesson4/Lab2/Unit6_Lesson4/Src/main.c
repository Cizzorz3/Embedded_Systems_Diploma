/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Adel
 * @brief          : Main program body
 *******************************************************************************
 */

/**
 * Description
 ******************************************************************************
Writing a code to enable the EXTI for the STM32F103C6
in each IRQ from the pushbutton the LED connected to Pin 13 will glow
used the AFIO to map the EXI
 *******************************************************************************
 */

typedef volatile unsigned int uint32_t ;

//Clock configuration
#define RCC_Base 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_Base+0x18)


//GPIO configuration
#define GPIOA_Base 0x40010800
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_Base+0x18)
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_Base+0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_Base+0x0c)

//EXTI configuration
#define EXTI_Base 0x40010400
#define EXTI0_IMR *(volatile uint32_t *)(EXTI_Base+0x00)
#define EXTI0_RTSR *(volatile uint32_t *)(EXTI_Base+0x08)
#define EXTI0_PR *(volatile uint32_t *)(EXTI_Base+0x14)

//AFI configuration
#define AFIO_Base 0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(EXTI_Base+0x08)

//NVIC configuration
#define NVIC_ISER0 *(volatile uint32_t *)(0xE000E100)


//TO initialize the clock for the APB2 Bus
void clock_init(void)
{
	//Enabling the clock to APB2 bus
	RCC_APB2ENR |= (1<<2);
	//Enabling the clock for the AFI
	RCC_APB2ENR |=(1<<0);
}
//TO initialize the GPIOA and Pin 13
void gpio_init()
{
	//clearing the GPIOA Port 13
	GPIOA_CRH &= 0xFF0FFFFF;
	//Setting the PA.13 LED
	GPIOA_CRH |= 0x00200000;
	//Setting PA.0 Push button
	GPIOA_CRL |= (1<<2);
}


int main(void)
{
	clock_init();
	gpio_init();
	//selecting the PA is the I/P port
	AFIO_EXTICR1 |= (0b0000<<0);
	//Opening the mask on EXTI0
	EXTI0_IMR |= (1<<0);
	//Enabling the rising edge trigger for EXT0
	EXTI0_RTSR |= (1<<0);
	// Mapping the NVIC for EXTI0 which is the 6 IRQ
	NVIC_ISER0 |=(1<<6);

	while(1);

}
//EXTI handler which is used to toggle the led
void EXTI0_IRQHandler(void)
{
	//toggle the LED
	GPIOA_ODR ^= (1<<13);
	//Clearing the pending status register to avoid IR overhead
	EXTI0_PR |=(1<<0);
}
