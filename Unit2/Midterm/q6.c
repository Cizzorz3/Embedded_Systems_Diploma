#include<stdio.h>
void unique(int arr[],int x){
    int repeated=0,i,j;
    for(i=0;i<x;i++){
        for(j=i+1;j<x;j++){
            if(arr[i]==arr[j]){
                break;
            }
            repeated+=1;
        }
        if(repeated>1){
            printf("%d ",arr[i]);
             break;
        }
        

    }

}
void main(){
    int a[7]={4,2,5,2,5,7,4};
    //int a[3]={4,2,4};
    int size = sizeof(a)/sizeof(*a);
    unique(a,size);


}