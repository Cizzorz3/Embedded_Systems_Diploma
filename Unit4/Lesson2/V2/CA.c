#include"CA.h"
//Variables
int CA_speed = 0 ;
int CA_distance = 0 ;
int CA_threshold = 50 ;


//State pointer is a pointer to function
void (*CA_state) ();

void US_Set_distance(int d){
    CA_distance = d;
    (CA_distance <= CA_threshold ) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;
    printf("US----------distance : %d --------" ,CA_distance);
}

STATE_define(CA_waiting){
    //State name
    CA_state_id = CA_waiting;
    printf("CA_waiting_state : distance : %d speed : %d \n",CA_distance , CA_speed);


    //state action
    CA_speed = 0 ;
     DC_motor(CA_speed);


    //event check
  

}
STATE_define(CA_driving){
      //State name
    CA_state_id = CA_driving;
    printf("CA_driving_state : distance : %d speed : %d \n",CA_distance , CA_speed);


    //state action
    CA_speed = 30 ;
    DC_motor(CA_speed);


    //event check

    
}
