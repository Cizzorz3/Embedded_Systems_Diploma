/*
 * UART.h
 *
 * Created: 7/14/2022 1:39:28 PM
 *  Author: Mohamed Adel
 */ 


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
//utlis
#define Read_Bit(reg,bit) ((reg>>bit)&1)
#define Sit_Bit(reg,bit) (reg |= (1<<bit))
#define Clear_Bit(reg,bit) (reg &=~ (1<<bit))
#define Toggle_Bit(reg,bit) (reg ^= (1<<bit))
#define Read_Bit(reg,bit) ((reg>>bit)&1)

//types
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
//Api
void uart_init(void);
void uart_send(uint8_t Data);
uint8_t uart_recieve(void);
void uart_send_string(uint8_t *Data);
uint8_t uart_recieve_string(void);


#endif /* UART_H_ */