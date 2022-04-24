#include<stdio.h>
void main(){
int x ;
float avg=0 , arr[100] , y;
printf("Enter the numbers of data: ");
scanf("%d",&x);
for(int i=0;i<x;i++){
    printf("%d. Enter number: ",i+1);
    scanf("%f",&y);
    arr[i]=y;
}
for(int i=0;i<x;i++){
    avg+=arr[i];
}
avg=avg/x;
printf("Average = %f",avg);












}