#include<stdio.h>
#include<string.h>
void Reverse_string(char a[] , int x){
    char temp[50];
    int b=0;
for(int i=x-1;i>=0;i--){
    temp[i]=a[b];
    b++;
}
for(int i=0;i<x;i++){
    printf("%c",temp[i]);
}
}
void main(){
    char sentence[50];
    printf("Enter a sentence: ");
    gets(sentence);
    Reverse_string(sentence,(int)strlen(sentence));
}