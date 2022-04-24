#include<stdio.h>
#include<string.h>


void main(){
    char str[20];
    char *p = NULL;
    int i =0;
    printf("input a string :");
    scanf("%s",str);
    p=str+(strlen(str)-1);
    for(i=strlen(str)-1;i>=0;i--){
        printf("%c",*p);
        p--;
    }
    
}