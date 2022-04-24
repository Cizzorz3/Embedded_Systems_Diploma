#include<stdio.h>


void main (){
    int a = 29;
    int *m = &a ;
    printf("Addres of m : 0x%x \n",m);
    printf("value of m : %d \n",*m);
    int *ab = m;
    printf("Addres of ab : 0x%x \n",m);
    printf("value of ab : %d \n",*m);
    *m = 34;
    printf("Addres of ab : 0x%x \n",m);
    printf("value of ab : %d \n",*m);
    *ab=7;
    printf("Addres of m : 0x%x \n",m);
    printf("value of m : %d \n",*m);



}