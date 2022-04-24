#include<stdio.h>
#include<string.h>
void main(){
int k=1;
char str[50],rev_str[50];
printf("Enter the string : ");
gets(str);
for(int i=0;i<strlen(str);i++){
    rev_str[i]=str[strlen(str)-k];
    k++;
}
rev_str[k-1]=0;
printf("Reverse string is : %s",rev_str);









}