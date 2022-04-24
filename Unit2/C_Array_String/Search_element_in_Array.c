#include<stdio.h>
void main(){

int x, arr[10],no,search;
printf("Enter no of elements : ");
scanf("%d",&x);
for(int i =0;i<x;i++){
    scanf("%d",&no);
    arr[i]=no;
}
for(int i =0;i>x;i++){
    printf("%d ",no);
}
printf("\n");
printf("Enter the elements to be searched : ");
scanf("%d",&search);
printf("\n");
for(int i=0;i<x;i++){
    if(arr[i]==search){
        printf("Number found at location = %d",i+1);
        break;
    }
}
}