#include<stdio.h>
void main(){

char c ;
printf("Enter a charachter: ");
fflush(stdin),fflush(stdout);
scanf("%c",&c);
if(c>97&&c<122){
    printf("%c is an alphabit",c);
}
else{
    printf("%c is not an alphabit",c);
}

}