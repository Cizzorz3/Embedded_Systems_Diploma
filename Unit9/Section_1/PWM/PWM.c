#include "PWM.h"

void PWM_init(enum Timer_Mode PWM , enum PWM_Mode PWM_type ,enum Prescaler Prescaler_type) 
{
    //This bit must be set to zero when TCCR0 is written when operating in PWM mode
    Clear_Bit(TCCR0,FOC0);
    //choosing PWM Mode
    if(PWM == Fast_PWM)
    {
        Set_Bit(TCCR0,WGM01);
        Set_Bit(TCCR0,WGM00);

    }
    if(PWM== PWM_Phase_Correct)
    {
        Clear_Bit(TCCR0,WGM01);
        Set_Bit(TCCR0,WGM00);


    }
    if(PWM_type == inverting_mode)
    {
        //Set OC0 on compare match, clear OC0 at BOTTOM,
        Set_Bit(TCCR0,COM01);
        Set_Bit(TCCR0,COM00);
        
    }
    if (PWM_type == non_inverting_mode)
    {
        //Clear OC0 on compare match, set OC0 at BOTTOM
        Set_Bit(TCCR0,COM01);
        Clear_Bit(TCCR0,COM00);
    }
    if(Prescaler_type == No_Prescaler)
    {
        Clear_Bit(TCCR0,CS02);
        Clear_Bit(TCCR0,CS01);
        Set_Bit(TCCR0,CS00);

    }
    else if(Prescaler_type==Prescaler_8)
    {
        Clear_Bit(TCCR0,CS02);
        Set_Bit(TCCR0,CS01);
        Clear_Bit(TCCR0,CS00);

    }
    else if(Prescaler_type==Prescaler_64)
    {
        Clear_Bit(TCCR0,CS02);
        Set_Bit(TCCR0,CS01);
        Set_Bit(TCCR0,CS00);

    }
    else if(Prescaler_type==Prescaler_256)
    {
        Set_Bit(TCCR0,CS02);
        Clear_Bit(TCCR0,CS01);
        Clear_Bit(TCCR0,CS00);

    }
    else if(Prescaler_type==Prescaler_1024)
    {
        Set_Bit(TCCR0,CS02);
        Set_Bit(TCCR0,CS01);
        Set_Bit(TCCR0,CS00);

    }
}


uint8_t PWM_output(void)
{
    return OCR0A
}