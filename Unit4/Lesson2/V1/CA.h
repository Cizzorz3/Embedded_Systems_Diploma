/*Author : Mohamed Adel*/
#ifndef __CA_H__
#define __CA_H__

#include"state.h"
//Define states
enum {
    CA_waiting , CA_driving
}CA_state_id;


//declare state functions for CA
STATE_define(CA_waiting);
STATE_define(CA_driving);


//State pointer is a pointer to function
extern void (*CA_state) ();
#endif