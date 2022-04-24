#include<stdio.h>
#include<math.h>
int prime_no(int x,int y){
    int i=2 , check=0;
 for(x;x<=y;x++){
     for(i;i<x;i++){
        if(x%i==0){
            i=2;
            check=0;
            break;
        }
        check=1;
        
     }   
     if(x==2){
         printf("%d ",x);
     }
     if(check==1)
     {
         printf("%d ",x);    
         check=0;
         i=2;

     }
 }
}
void main(){
    int x,y ;
    scanf("%d %d",&x,&y);
    prime_no(x,y);
   

}