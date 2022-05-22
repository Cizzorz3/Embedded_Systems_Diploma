#ifndef Pressure_Sensor_H_
#define Pressure_Sensor_H_
#include"global_headers.h"
#define Threshold 20
int pressure_value;
typedef enum {
    Pressure_Threshold_Have_Been_Passed , 
    Pressure_is_LessThan_Threshold
}Current_Pressure_Sensor_Reading;
//APIS
int getPressureVal();
Current_Pressure_Sensor_Reading check_Pressure_val();


#endif