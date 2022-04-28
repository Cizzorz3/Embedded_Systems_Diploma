#include"CA.c"

void setup(){
    //init all the drivers
    //init IRQ
    //init HAL
    //init block
    //set states pointers for each block
    CA_state = STATE(CA_waiting);

}
void main(){
    volatile int d;
    setup();
    while (1)
    {
        //call each state
        CA_state();
        for(d=0;d<=1000;d++);
    }
    

}