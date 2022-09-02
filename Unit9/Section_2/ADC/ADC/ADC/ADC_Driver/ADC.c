/*
 * ADC.c
 *
 * Created: 9/2/2022 2:31:45 PM
 *  Author: Mohamed Adel
 */ 
#include "ADC.h"


void ADC_init(enum refrence_selection_bits refrence_selection,enum ADC_Channel_selection ADC_channel , enum Prescale_bits Prescaler)
{
	Set_Bit(ADCSRA,ADEN);
	if(refrence_selection ==Vref_Off )
	{
		Clear_Bit(ADMUX,REFS1);
		Clear_Bit(ADMUX,REFS0);
	}
	else if(refrence_selection==VCC_EXT_Cap)
	{
		Clear_Bit(ADMUX,REFS1);
		Set_Bit(ADMUX,REFS0);
	}
	else if(refrence_selection==Reserved)
	{
		Set_Bit(ADMUX,REFS1);
		Clear_Bit(ADMUX,REFS0);
		
	}
	else if(refrence_selection==internal_2_56V)
	{
		Set_Bit(ADMUX,REFS1);
		Set_Bit(ADMUX,REFS0);
	}
	if(ADC_channel==ADC0)
	{
		Clear_Bit(ADMUX,MUX0);
		Clear_Bit(ADMUX,MUX1);
		Clear_Bit(ADMUX,MUX2);
		Clear_Bit(ADMUX,MUX3);
		Clear_Bit(ADMUX,MUX4);
	}
	else if(ADC_channel==ADC1)
	{
		Set_Bit(ADMUX,MUX0);
		Clear_Bit(ADMUX,MUX1);
		Clear_Bit(ADMUX,MUX2);
		Clear_Bit(ADMUX,MUX3);
		Clear_Bit(ADMUX,MUX4);
	}
	else if(ADC_channel==ADC2)
	{
		Clear_Bit(ADMUX,MUX0);
		Set_Bit(ADMUX,MUX1);
		Clear_Bit(ADMUX,MUX2);
		Clear_Bit(ADMUX,MUX3);
		Clear_Bit(ADMUX,MUX4);
	}
	else if(ADC_channel==ADC3)
	{
		Set_Bit(ADMUX,MUX0);
		Set_Bit(ADMUX,MUX1);
		Clear_Bit(ADMUX,MUX2);
		Clear_Bit(ADMUX,MUX3);
		Clear_Bit(ADMUX,MUX4);
	}
	else if(ADC_channel==ADC4)
	{
		Clear_Bit(ADMUX,MUX0);
		Clear_Bit(ADMUX,MUX1);
		Set_Bit(ADMUX,MUX2);
		Clear_Bit(ADMUX,MUX3);
		Clear_Bit(ADMUX,MUX4);
	}
	else if(ADC_channel==ADC5)
	{
		Set_Bit(ADMUX,MUX0);
		Clear_Bit(ADMUX,MUX1);
		Set_Bit(ADMUX,MUX2);
		Clear_Bit(ADMUX,MUX3);
		Clear_Bit(ADMUX,MUX4);
	}
	else if(ADC_channel==ADC6)
	{
		Clear_Bit(ADMUX,MUX0);
		Set_Bit(ADMUX,MUX1);
		Set_Bit(ADMUX,MUX2);
		Clear_Bit(ADMUX,MUX3);
		Clear_Bit(ADMUX,MUX4);
	}
	else if(ADC_channel==ADC7)
	{
		Set_Bit(ADMUX,MUX0);
		Set_Bit(ADMUX,MUX1);
		Set_Bit(ADMUX,MUX2);
		Clear_Bit(ADMUX,MUX3);
		Clear_Bit(ADMUX,MUX4);
	}
	
		switch(Prescaler)
		{
			case Prescaler_2 :
			Clear_Bit(ADCSRA,ADPS2);
			Clear_Bit(ADCSRA,ADPS1);
			Clear_Bit(ADCSRA,ADPS0);
			break;
			case Prescaler_4 :
			Clear_Bit(ADCSRA,ADPS2);
			Set_Bit(ADCSRA,ADPS1);
			Clear_Bit(ADCSRA,ADPS0);
			break;
			case Prescaler_8 :
			Clear_Bit(ADCSRA,ADPS2);
			Set_Bit(ADCSRA,ADPS1);
			Set_Bit(ADCSRA,ADPS0);
			break;
			case Prescaler_16 :
			Set_Bit(ADCSRA,ADPS2);
			Clear_Bit(ADCSRA,ADPS1);
			Clear_Bit(ADCSRA,ADPS0);
			break;
			case Prescaler_32 :
			Set_Bit(ADCSRA,ADPS2);
			Clear_Bit(ADCSRA,ADPS1);
			Set_Bit(ADCSRA,ADPS0);
			break;
			case Prescaler_64 :
			Set_Bit(ADCSRA,ADPS2);
			Set_Bit(ADCSRA,ADPS1);
			Clear_Bit(ADCSRA,ADPS0);
			break;
			case Prescaler_128 :
			Set_Bit(ADCSRA,ADPS2);
			Set_Bit(ADCSRA,ADPS1);
			Set_Bit(ADCSRA,ADPS0);
			break;
			
		}
}
uint16_t ADC_read(void)
{
	//Writing this bit to one enables the ADC. By writing it to zero, the ADC is turned off
	Set_Bit(ADCSRA,ADEN);
	Set_Bit(ADCSRA,ADSC);
	while(!(Read_Bit(ADCSRA,ADIF)));
	Set_Bit(ADCSRA,ADIF);
	return ADC;
	
}