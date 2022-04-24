#include<stdio.h>
#include<string.h>
void Reverse_string(char a[] , int x){
    char temp[50];
    int b=0 ,l ,j,tem;
for(int i=x-1;i>=0;i--){
    if(a[i]==' '){
        tem=i-1;
        for(l=b-1;l>=0;l--){
            printf("%c",temp[l]);
        }
        printf(" ");
    }
    l=0;
    temp[b]=a[i];
    b++;
}

for(j=x-1;j>=tem-1;j--){
    printf("%c",temp[j]);

}



}
void main(){
    char sentence[50];
    printf("Enter a sentence: ");
    gets(sentence);
    Reverse_string(sentence,(int)strlen(sentence));
}