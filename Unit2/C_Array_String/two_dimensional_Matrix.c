#include<stdio.h>
void main(){

float x[2][2] , y[2][2] , num , sum[2][2];

printf("Enter the elements of the 1st Matrix \n");
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        printf("Enter a%d%d: ",i+1,j+1);
        scanf("%f",&num);
        x[i][j]=num;
    }
}
printf("Enter the elements of the 2nd Matrix \n");
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        printf("Enter b%d%d: ",i+1,j+1);
        scanf("%f",&num);
        y[i][j]=num;

    }
}
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        sum[i][j]=(x[i][j]+y[i][j]);

    }
}
printf("Sum of Matrix: \n");
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        printf("%f ",sum[i][j]);
    }
    printf("\n");
}





}