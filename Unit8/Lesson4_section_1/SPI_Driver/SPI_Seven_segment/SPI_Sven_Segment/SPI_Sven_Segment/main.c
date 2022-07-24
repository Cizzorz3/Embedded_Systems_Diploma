/*
 * SPI_Sven_Segment.c
 *
 * Created: 7/24/2022 12:54:04 AM
 * Author : Mohamed Adel
 */ 

#include "SPI/SPI.h"
#include <util/delay.h>
void send_cmd(uint8_t Add , uint8_t value)
{
	 PORTB&=~(1<<SS);
	 /*Send the command*/
	 SPDR=Add;
	 while(!(SPSR&(1<<SPIF)));
	 SPDR=value;
	 while(!(SPSR&(1<<SPIF)));

	 PORTB|=(1<<SS);
	
}
int main(void)
{
	uint8_t a=0 , i;
	spi_master_output_init();
	send_cmd(0x09,0xff);
	send_cmd(0x0A,0xff);
	send_cmd(0x0B,0xf7);
	send_cmd(0x0c,0x01);
    /* Replace with your application code */
    while (1) 
    {

		for(i=1;i<9;i++)
		{
			send_cmd(i,a++);
			_delay_ms(1000);
		
		}
	
		
    }
}

