#include<stdio.h>
void main(){

int x ,prod=1;
for(int i=1;i<=4;i++){
    printf("Enter num%d:",i);
    scanf("%d",&x);
    if(x==0)continue;
    else{
    prod*=x;
    }
}
printf("product=%d",prod);









}