/*
 * Keypad_Driver.h
 *
 * Created: 6/24/2022 10:57:52 AM
 *  Author: Mohamed Adel
 */ 


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

#undef F_CPU
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define Keypad_PORT PORTD
#define Keypad_PORT_Dir DDRD
#define Keypad_Pin PIND
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7


void keypad_init(void);
char keyoad_getchar();



#endif /* KEYPAD_DRIVER_H_ */