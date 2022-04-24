#include<stdio.h>
void reverse_array(int arr[],int x){
    int temp [50];
    int i , y=0 ,j ,k ;
    for(i=x-1;i>=0;i--){
        if(arr[i]==' '){
            for(k=i;k>=0;k--){
                printf("%d",temp[k]);

            }
        }
        temp[y]=arr[i];
        y++;

    }
    for(j=0;j<x;j++){
        printf("%d ",temp[j]);
    }
}
void main(){
    int size;
    int arr[]={1,2,3,4,5};
    size=sizeof(arr)/sizeof(*arr);
    reverse_array(arr,size);
}