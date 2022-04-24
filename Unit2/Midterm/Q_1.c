#include <stdio.h>
int sum=0;
int sum_digits(int a){
    
    if (a>0)
    {
        sum+=a%10;
        a/=10;
        sum_digits(a);
    }
    else{
        return sum;
    }

    
}
int main()
{
    int x ,  add ;
    scanf("%d",&x);
    add= sum_digits(x);
    printf("%d",add);

    return 0;
}