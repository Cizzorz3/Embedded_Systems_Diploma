#include"CA.h"
//Variables
int CA_speed = 0 ;
int CA_distance = 0 ;
int CA_threshold = 50 ;


//State pointer is a pointer to function
void (*CA_state) ();
int get_random(int l , int r , int count);


STATE_define(CA_waiting){
    //State name
    CA_state_id = CA_waiting;

    //state action
    CA_speed = 0 ;

    CA_distance = get_random(45,55,1);

    //event check
    (CA_distance <= CA_threshold ) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;

    printf("CA_waiting_state : distance : %d speed : %d \n",CA_distance , CA_speed);
}
STATE_define(CA_driving){
      //State name
    CA_state_id = CA_driving;

    //state action
    CA_speed = 30 ;

    CA_distance = get_random(45,55,1);
    //event check
    (CA_distance <= CA_threshold ) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;

    printf("CA_driving_state : distance : %d speed : %d \n",CA_distance , CA_speed);
    
}
int get_random(int l , int r , int count){
     int i ;
     for(i =0 ; i<count ; i++){
         int rand_num = (rand()%(r-l+1))+l;
         return rand_num;
     }
}