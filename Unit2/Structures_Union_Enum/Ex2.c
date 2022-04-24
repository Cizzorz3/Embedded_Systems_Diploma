#include<stdio.h>
struct Distance
{
    int feet;
    double inch;
};

void main(){
    struct Distance d1 , d2 , sum;
    printf("Enter information for 1st Distance : \n");
    printf("Enter feet: ");
    scanf("%d",&d1.feet);
    printf("Enter inch: ");
    scanf("%lf",&d1.inch);

    printf("Enter information for 2nd Distance : \n");
    printf("Enter feet: ");
    scanf("%d",&d2.feet);
    printf("Enter inch: ");
    scanf("%lf",&d2.inch);

    sum.feet=d1.feet+d2.feet;
    sum.inch=d1.inch+d2.inch;

    if(sum.inch>12){
        sum.inch=sum.inch-12.0;
        ++sum.feet;
    }
    printf(" Sum of distances = %d - %lf ",sum.feet,sum.inch);
    



}