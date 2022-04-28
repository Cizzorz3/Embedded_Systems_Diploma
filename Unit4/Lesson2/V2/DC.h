/*Author : Mohamed Adel*/
#ifndef __DC_H__
#define __DC_H__

#include"state.h"
//Define states
enum {
    DC_idle , DC_busy
}DC_state_id;


//declare state functions for CA
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();
void DC_motor(int s);
//State pointer is a pointer to function
extern void (*DC_state) ();
#endif