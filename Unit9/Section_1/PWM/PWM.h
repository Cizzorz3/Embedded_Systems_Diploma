/**
 * @file PWM.h
 * @author Mohamed Adel (mohamedaadelezz3@gmail.com)
 * @brief Header file for the PWM driver for Atmega32
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <avr/io.h>

#define Read_Bit(reg,bit) ((reg>>bit)&1)
#define Set_Bit(reg,bit) (reg |= (1<<bit))
#define Clear_Bit(reg,bit) (reg &=~ (1<<bit))
#define Toggle_Bit(reg,bit) (reg ^= (1<<bit))
#define Read_Bit(reg,bit) ((reg>>bit)&1)


enum Timer_Mode
{
    Fast_PWM ,
    PWM_Phase_Correct
};
enum PWM_Mode
{
    inverting_mode ,
    non_inverting_mode
};
enum Prescaler
{
    No_Prescaler ,
    Prescaler_8 ,
    Prescaler_64 ,
    Prescaler_256 ,
    Prescaler_1024 
};
void PWM_init(void);