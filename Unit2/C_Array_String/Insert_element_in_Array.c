#include<stdio.h>
void main(){

int arr[10],x,y,location,k=0,arr2[10];
printf("Enter no of elements :");
scanf("%d",&x);
for(int i=0;i<x;i++){
    arr[i]=i+1;
    printf("%d ",arr[i]);
}
printf("\n");
printf("Enter the element to be inserted : ");
scanf("%d",&y);
printf("Enter the location: ");
scanf("%d",&location);
//replaced=arr[location-1];
for(int i=(location-1);i<x;i++){
    arr2[k]=arr[i];
    k++;
}
arr[location-1]=y;
for(int i=0;i<location;i++){
    printf("%d ",arr[i]);
}

for(int i=0;i<x-1;i++){
    printf("%d ",arr2[i]);
}





}