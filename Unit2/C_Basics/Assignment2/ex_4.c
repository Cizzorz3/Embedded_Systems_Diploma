#include<stdio.h>
void main(){

float x;
printf("Enter a number : ");
fflush(stdout),fflush(stdin);
scanf("%f",&x);

if(x>0){
    printf("%f is positive",x);
}
else if(x==0){
    printf("You entered zero");
}
else{
    ("%f is negative",x);
}



}