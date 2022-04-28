#include "CA.h"
#include "US.h"
#include "DC.h"

void setup(){
    //init all the drivers
    //init IRQ
    //init HAL
    //init block
    US_init();
    DC_init();
    //set states pointers for each block
    CA_state = STATE(CA_waiting);
    US_state = STATE(US_busy);
    DC_state = STATE(DC_idle);

}
void main(){
    volatile int d;
    setup();
    while (1)
    {
        //call each state
        US_state();
        CA_state();
        DC_state();
        for(d=0;d<=1000;d++);
    }
    

}