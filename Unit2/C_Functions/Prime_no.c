#include<stdio.h>

void prime_no(int x, int y){
  int check=0;
for(int i=x;i<y;i++){
    for(int k=2;k<i;k++){
        if(i%k==0){
            break;
        }
        if(k==x-1){
            check=1;
        }
        else{
            continue;
        }

    }
    if(check==1){
        printf("%d ",i);
        check=0;
    }
    
}
}
void main(){
int x,y;
printf("Enter two no for the boundries");
scanf("%d %d",&x , &y);
prime_no(x,y);



}