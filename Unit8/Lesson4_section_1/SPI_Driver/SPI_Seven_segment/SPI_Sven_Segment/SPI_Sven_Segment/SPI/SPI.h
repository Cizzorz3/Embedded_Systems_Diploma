/*
 * SPI.h
 *
 * Created: 7/21/2022 4:15:12 AM
 *  Author: Mohamed Adel
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>
typedef unsigned char uint8_t;
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

void spi_master_output_init(void);
void spi_slave_output_init(void);
uint8_t spi_master_send_char(uint8_t Data);
uint8_t spi_slave_recieve_char(uint8_t Data);





#endif /* SPI_H_ */