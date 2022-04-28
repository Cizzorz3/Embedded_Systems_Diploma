#include"DC.h"
//Variables
int DC_speed = 0 ;
//State pointer is a pointer to function
void (*DC_state) ();

void DC_init(){
    //init PWM
    printf("DC init \n");
}
void DC_motor( int s){
    DC_speed = s;
    DC_state = STATE(DC_busy);
    printf("DC---------------speed : %d ----------- \n",DC_speed);
}
STATE_define(DC_idle){
    //State name
    DC_state_id = DC_idle;

    printf("DC_idle  speed : %d \n", DC_speed);
}
STATE_define(DC_busy){
      //State name
    DC_state_id = DC_busy;

    //state action
    DC_state = STATE(DC_idle);

printf("DC_busy  speed : %d \n", DC_speed);

    
}
