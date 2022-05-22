#include "Pressure_Sensor_Driver.h"
int getPressureVal()
{
	return (GPIOA_IDR & 0xFF);
}
Current_Pressure_Sensor_Reading check_Pressure_val()
{
    pressure_value=getPressureVal();
    if(pressure_value>Threshold){
        return(Pressure_Threshold_Have_Been_Passed) ;
    }
    else if (pressure_value<Threshold){
        return(Pressure_is_LessThan_Threshold) ;

    }
}

