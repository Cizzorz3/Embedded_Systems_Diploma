#include<stdio.h>
#include<string.h>
void main(){

char str[50],c,repeat=0;
printf("Enter a string: ");
gets(str);
printf("Enter a charachter to find frequenc: ");
scanf("%c",&c);
for(int i=0;i<strlen(str);i++){
    if(str[i]==c){
        repeat+=1;
    }
}
printf("Frequency of %c = %d",c,repeat);











}