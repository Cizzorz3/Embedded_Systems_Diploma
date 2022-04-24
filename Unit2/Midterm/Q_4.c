#include<stdio.h>
void reverse(int x){
    int temp;
    while (x>0)
    {
        temp=x%10;
        printf("%d",temp);
        x/=10;
    }
    
}
void main(){
    int x;
    scanf("%d",&x);
    reverse(x);
}