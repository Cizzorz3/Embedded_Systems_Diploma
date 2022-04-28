#ifndef _State_H__
#define _State_H__

#include<stdio.h>
#include<stdlib.h>
//Automatic state function generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

//states connections
void US_Set_distance(int d);
void DC_motor(int s);

#endif