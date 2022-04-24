#include<stdio.h>
void count_ones(int x){
    int i , cnt=0,max=0;
    while (x>0)
    {
        if(x&1){
            cnt++;
            x=x>>1;
        }
        else{
            if(max==1){
                max=0;
                break;
            }
         max=1;
         x=x>>1;
        }
    }
    printf("%d",cnt);
    
}
void main(){
    int x;
    scanf("%d",&x);
    count_ones(x);

}