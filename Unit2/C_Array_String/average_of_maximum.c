#include<stdio.h>

void main(){

int x;
float avg=0,y,sum=0;
printf("Maximum no, of inputs \n");
fflush(stdin),fflush(stdout);
scanf("%d",&x);
for(int i=1;i<=x;i++){
    printf("Enter n%d: ",i);
    scanf("%f",&y);
    if(y<0)
    {
        break;
    }
    else
    {
        sum+=y;
    }
}
avg=sum/(x-1);
printf("Average=%f",avg);




}