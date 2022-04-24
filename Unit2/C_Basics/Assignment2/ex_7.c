#include<stdio.h>
void main(){
    int x , factorial=1;
    printf("Enter an integer: ");
    fflush(stdout),fflush(stdin);
    scanf("%d",&x);
    if(x>0){
        for(int i=1;i<=x;i++){
            factorial*=i;
        }
        printf("Factorial = %d",factorial);
    }
    else if(x==0){
        printf("Factorial = %d",0);
    }
    else{
        printf("Error!!! Facotiral of negative number doesn't exist");
    }
}