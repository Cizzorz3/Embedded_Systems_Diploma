#include<stdio.h>

struct complex{
    float real;
    float img;
}d1,d2;
void Add_Two_Complex(struct complex x,struct complex y){
    struct complex sum;
    sum.real=x.real+y.real;
    sum.img=x.img+y.img;
    printf("Sum= %.1f + %.1fi",sum.real,sum.img);
}
void main(){
    printf("For 1st complex number ");
    printf("Enter real and imaginary respectivley: ");
    scanf("%f %f",&d1.real,&d1.img);
    printf("For 2nd complex number ");
    printf("Enter real and imaginary respectivley: ");
    scanf("%f %f",&d2.real,&d2.img);
    Add_Two_Complex(d1,d2);
    


    

}