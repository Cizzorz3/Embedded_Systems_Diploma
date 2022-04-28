#include"US.h"
//Variables
int US_distance = 0 ;
//State pointer is a pointer to function
void (*US_state) ();

void US_init(){

    printf("US init \n");
}

STATE_define(US_busy){
    //State name
    US_state_id = US_busy;

    //state action

    US_distance = get_random(45,55,1);

    //event check

    printf("US_waiting_state : distance : %d \n",US_distance);
    US_Set_distance(US_distance);
    US_state = STATE(US_busy);
}
