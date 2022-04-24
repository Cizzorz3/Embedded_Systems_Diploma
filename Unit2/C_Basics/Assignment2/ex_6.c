#include<stdio.h>
void main(){

int x ,sum=0;
printf("Enter an integer: ");
fflush(stdout),fflush(stdin);
scanf("%d",&x);
for(int i=1;i<=x;i++){
    sum+=i;
}
printf("Sum = %d",sum);



}