#include<stdio.h>

void main(){

    int arr[5]={2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *p =arr+(size-1);
    int i;
    for(i=size;i>0;i--){
        printf("%d ",*p);
        p--;
    }
  
}