#include "Alarm_Manager.h"
volatile RegODR_t* RegODR = (volatile RegODR_t*)(GPIO_PORTA + 0x0c);
void Alarm_ON(){
    RegODR->bits.bit13=0;
   RESET_BIT(GPIOA_ODR,13);
    Delay(60);
}
void Alarm_OFF(){
    RegODR->bits.bit13=1;
    SET_BIT(GPIOA_ODR,13);
}
void Delay(int nCount)
{
	for(; nCount != 0; nCount--);
}
