/*
 * Lab2.c
 *
 * Created: 6/20/2022 11:09:58 PM
 * Author : Mohamed Adel
 */ 

/************************************************************************/
/* Driver for Atmega32 to turn on LED sequentially at Port D pin 5 , 6 and 7 
	and after that opens a buzzer then repeats the same process again                                               
 */
/************************************************************************/
typedef unsigned int uint32_t ;
//Base Address of the IO
#define IO_Base 0x20

//PortD config
#define PORTD_IO *(volatile uint32_t * ) (IO_Base+0x12)
#define DDRD_IO *(volatile uint32_t * ) (IO_Base+0x11)

//IO initialization
void IO_init(void)
{
	//setting pin 4,5,6,7 as outputs
	DDRD_IO |= (1<<5) | (1<<6) | (1<<7) | (1<<4);
	//resetting all the values on PORTD
	PORTD_IO = 0;
}
//time delay function
void delay_ms(uint32_t p)
{
	uint32_t i , j;
	for(i=0;i<p;i++){
		for(j=0;j<255;j++);
	}
}

int main(void)
{
	IO_init();
    /* Replace with your application code */
    while (1) 
    {
		//setting PD.5
		PORTD_IO |= (1<<5);
		//wait for 3 seconds
		delay_ms(3000);
		//clearing PD.5
		PORTD_IO &= ~(1<<5);
		//setting PD.6
		PORTD_IO |= (1<<6);
		delay_ms(3000);
		//clearing PD.6
		PORTD_IO &= ~(1<<6);
		//setting PD.7
		PORTD_IO |= (1<<7);
		delay_ms(3000);
		//clearing PD.7
		PORTD_IO &= ~(1<<7);
		//Enabling buzzer at PD.4
		PORTD_IO |= (1<<4);
		delay_ms(3000);
		//disabling buzzer at PD.4
		PORTD_IO &= ~(1<<4);
		
		
    }
}

