#include"Init.h"
#include"Alarm_Manager.h"
#include"Pressure_Sensor_Driver.h"
int main (){
	init();
	while (1)
	{
		
		if(check_Pressure_val()==Pressure_is_LessThan_Threshold){
			Alarm_OFF();
		}
		else if(check_Pressure_val()==Pressure_Threshold_Have_Been_Passed){
			Alarm_ON();
		}
	}
}
