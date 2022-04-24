#include<stdio.h>
int sum=1;
void fact(int x){
    if(x>0){
        sum*=x;
        x--;
        fact(x);
    }
    else{
    printf("%d ",sum);

    }
}
void main(){
    int x;
    printf("Enter a positive no");
    scanf("%d",&x);
    fact(x);
}