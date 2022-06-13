/*
 * Interrupt_LED.c
 *
 * Created: 6/13/2022 8:03:06 PM
 * Author : Mohamed Adel
 */ 

/************************************************************************/
/* Enabling External Interrupt on ATmega32
	Enabling INT0 , INT1, INT2 and connecting them to push buttons in order to change their state
	Configuring PD5 PD6 PD7 as outputs and connecting them to lED and each led lights up for 1 second                     
 */
/************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int main(void)
{
	//Enabling the interrupts of INT0 , INT1 ,INT2 of the General Interrupt Control Register to 1110 0000
	GICR |= 0xE0;
	// Choosing the	edge detection for the pins of the MCU Control Register to for rising edge (11) for any logic (01)
	MCUCR |= 0xD;
	//Choosing falling edge in ISC2 for the INT2 
	MCUCSR |= (0<<6);
	//Enabling all the global interrupts
	sei();
	//setting (PD7 PD6 PD5 as outputs ), (PD2 PD3 as inputs)
	DDRD |= 0b11100000 ;
	//setting PORTB as inputs
	DDRB |=0;
    /* Replace with your application code */
    while (1) ;
}

//INT0 interrupt handler
ISR (INT0_vect) 
{
	//output 1 on PD5
	PORTD |= (1<<5);
	_delay_ms(10000);
	//Clearing PD5
	PORTD &= ~(1<<5);
	
}
ISR (INT1_vect)
{
	//output 1 on PD6
	PORTD |= (1<<6);
	_delay_ms(10000);
	//Clearing PD6
	PORTD &= ~(1<<6);
}
ISR (INT2_vect)
{
	//output 1 on PD7
	PORTD |=(1<<7);
	_delay_ms(10000);
	//Clearing PD7
	PORTD &= ~(1<<7);
}