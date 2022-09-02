/*
 * ADC.h
 *
 * Created: 9/2/2022 2:31:54 PM
 *  Author: Mohamed Adel
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#define Read_Bit(reg,bit) ((reg>>bit)&1)
#define Set_Bit(reg,bit) (reg |= (1<<bit))
#define Clear_Bit(reg,bit) (reg &=~ (1<<bit))
#define Toggle_Bit(reg,bit) (reg ^= (1<<bit))
#define Read_Bit(reg,bit) ((reg>>bit)&1)



enum refrence_selection_bits
{
	Vref_Off,
	VCC_EXT_Cap,
	Reserved,
	internal_2_56V	
	
};

enum ADC_Channel_selection
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,

};
enum Prescale_bits
{
	Prescaler_2,
	Prescaler_4,
	Prescaler_8,
	Prescaler_16,
	Prescaler_32,
	Prescaler_64,
	Prescaler_128,
	
	
		
};
void ADC_init(enum refrence_selection_bits refrence_selection,enum ADC_Channel_selection ADC_channel , enum Prescale_bits Prescaler);
uint16_t ADC_read();
#endif /* ADC_H_ */