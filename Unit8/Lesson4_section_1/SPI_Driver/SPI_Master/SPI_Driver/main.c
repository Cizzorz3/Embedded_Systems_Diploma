/*
 * SPI_Driver.c
 *
 * Created: 7/21/2022 4:12:08 AM
 * Author : Mohamed Adel
 */ 


#include "SPI/SPI.h"
#include <util/delay.h>
int main(void)
{
	uint8_t c ;
	spi_master_output_init();
	DDRA = 0xff;
	for(c=0;c<=55;c++)
	{
		_delay_ms(1000);
		PORTA = spi_master_send_char(c);
	}

}

