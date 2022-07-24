/*
 * GccApplication1.c
 *
 * Created: 7/21/2022 4:41:50 AM
 * Author : 101
 */ 

#include <avr/io.h>
#include <util/delay.h>
typedef unsigned char uint8_t;
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7
void spi_master_output_init(void);
void spi_slave_output_init(void);
uint8_t spi_master_send_char(uint8_t Data);
uint8_t spi_slave_recieve_char(uint8_t Data);
void spi_slave_output_init(void)
{
	SPCR |= (1<<SPE) ;
	DDRB |= (1<<MISO) ;
}
uint8_t spi_slave_recieve_char(uint8_t Data)
{
	
	SPDR = Data;
	while(!SPSR & (1<<SPIF));
	return SPDR;
}

int main(void)
{
		uint8_t c ;
		spi_slave_output_init();
		DDRA = 0xff;
		for(c=255;c>=0;c--)
		{
			_delay_ms(1000);
			PORTA = spi_slave_recieve_char(c);
		}

}

