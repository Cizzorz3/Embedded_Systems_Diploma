#ifndef _Alarm_Manager_H__
#define _Alarm_Manager_H__
#include"global_headers.h"
typedef volatile unsigned int vuint32_t;//bit field
typedef union
{

  struct 
  {
    vuint32_t reserved:13;
    vuint32_t bit13:1;
    
  } bits;

  vuint32_t All_fields;

} RegODR_t;


//APIS
void Recieve_Pressure_val(int i);
void Alarm_ON();
void Alarm_OFF();
void Delay(int nCount);

#endif