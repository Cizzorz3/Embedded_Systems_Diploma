#include<stdio.h>
int temp;
void power(int x,int y){
    if(y>1){
        x*=temp;
        y--;
        power(x,y);
    }
    else{
        printf("%d",x);
    }
}

void main(){
    int x , y;
    printf("Enter base number: ");
    scanf("%d" ,&x);
    printf("Enter power number(positive integer): ");
    scanf("%d" ,&y);
    temp=x;
    power(x,y);
    
}