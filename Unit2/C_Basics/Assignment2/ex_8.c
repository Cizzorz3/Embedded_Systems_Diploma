#include<stdio.h>
void main(){

    float x , y;
    char c;
    printf("Enter operator either + or - or * or divide : ");
    fflush(stdin),fflush(stdout);
    scanf("%c",&c);
    printf("Enter two operands: ");
    fflush(stdin),fflush(stdout);
    scanf("%f %f",&x,&y);
    switch (c)
    {
    case '+':
        printf("%f",x+y);
        break;
    case '-':
        printf("%f",x-y);
        break;
    case'*' :
        printf("%f",x*y);
        break;
    case '/':
        printf("%f",x/y);
        break;
    default:
        break;
    }



}