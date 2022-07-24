/*
 * SPI.c
 *
 * Created: 7/21/2022 4:15:22 AM
 *  Author: Mohamed Adel
 */ 
#include "SPI.h"

void spi_slave_output_init(void)
{
	SPCR |= (1<<SPE) ;
	DDRB |= (1<<MISO) ;
}

void spi_master_output_init(void)
{
	SPCR = (1<<SPR0) | (1<<MSTR) | (1<<SPE) ;
	DDRB = (1<<SS) | (1<<MOSI) | (1<<SCK);
}

uint8_t spi_master_send_char(uint8_t Data)
{
	SPDR = Data;
	while(!SPSR & (1<<SPIF));
	return SPDR;

}
uint8_t spi_slave_recieve_char(uint8_t Data)
{
	
	SPDR = Data;
	while(!SPSR & (1<<SPIF));
	return SPDR;
}
