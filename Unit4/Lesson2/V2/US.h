/*Author : Mohamed Adel*/
#ifndef __US_H__
#define __US_H__

#include"state.h"
//Define states
enum {
   US_busy
}US_state_id;


//declare state functions for CA
STATE_define(US_busy);

void US_init();
//State pointer is a pointer to function
extern void (*US_state) ();
#endif