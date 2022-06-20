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

//GPIOA configurations
#define GPIOA_Base 0x40010800
//Note Reset value: 0x4444 4444
#define GPIOA_CRL *(volatile unsigned int *)(GPIOA_Base+0x00)
#define GPIOA_CRH *(volatile unsigned int *)(GPIOA_Base+0x04)
#define GPIOA_IDR *(volatile unsigned int *)(GPIOA_Base+0x08)
#define GPIOA_ODR *(volatile unsigned int *)(GPIOA_Base+0x0C)
//GPIOB configurations
#define GPIOB_Base 0x40010C00
//Note Reset value: 0x4444 4444
#define GPIOB_CRL  *(volatile unsigned int *)(GPIOB_Base+0x00)
#define GPIOB_CRH  *(volatile unsigned int *)(GPIOB_Base+0x04)
#define GPIOB_IDR  *(volatile unsigned int *)(GPIOB_Base+0x08)
#define GPIOB_ODR  *(volatile unsigned int *)(GPIOB_Base+0x0C)

//Clock configurations
#define RCC_Base   0x40021000
#define RCC_APB2ENR *(volatile unsigned int *)(RCC_Base+0x18)

void gpio_init(void)
{
	//Resetting all the values of the CRL registers
	GPIOA_CRL =0;
	GPIOB_CRL =0;
	//PA 1  CNF1 as a floating input
	GPIOA_CRL |= (0b01<<6);
	//PA 1  Mode1 as a input mode
	GPIOA_CRL |= (0b00<<4);
	//PB 1  Mode1 as a output with max 10MHZ
	GPIOB_CRL |= (0b01<<4);
	//PB 1  CNF1 as a push pull output
	GPIOB_CRL |= (0b00<<6);

	//Resetting all the values of the CRH registers
	GPIOA_CRH=0;
	GPIOB_CRH =0;
	//PA 13  CNF13 as a floating input
	GPIOA_CRH |= (0b01<<22);
	//PA 1  Mode13 as a  input mode
	GPIOA_CRH |= (0b00<<20);
	//PB 13  CNF13 as a output with max 10MHZ
	GPIOB_CRH |= (0b00<<22);
	//PB 13  Mode13 as a push pull output
	GPIOB_CRH |= (0b01<<20);

}

void clock_init(void)
{
	//Enabling the clock
	RCC_APB2ENR |= (1<<2);
	RCC_APB2ENR |=(1<<3);
}

void delay_ms(unsigned int p)
{
	//delay function
	unsigned int i ,j;
	for(i=0;i<p;i++ ){
		for(j=0;j<255;j++);
	}
}
int main ()
{
	clock_init();
	gpio_init();

	while(1)
		{
			if ((GPIOA_IDR &(1<<1))==0)
			{
				GPIOB_ODR ^= (1<<1);
				while ((GPIOA_IDR & (1<<1))== 0);
			}
			if (((GPIOA_IDR & (1<<13))>>13) == 1)
					{
						while(((GPIOA_IDR & (1<<13))>>13) == 1)
						{
							GPIOB_ODR ^= (1<<13);
							delay_ms(1);
						}
					}


		}
}
