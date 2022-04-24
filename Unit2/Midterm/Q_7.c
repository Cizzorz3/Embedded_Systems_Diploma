#include<stdio.h>
int sum;
int i=0;
void sum_to_hundred(){
    while(i<=100){
        sum+=i;
        i++;
    }
    printf("%d ",sum);
}
void main(){
    sum_to_hundred();
}