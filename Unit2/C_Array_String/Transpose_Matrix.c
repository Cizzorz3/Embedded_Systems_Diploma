#include<stdio.h>
void main(){


int x ,y , arr[10][10] , no,transpose_Matrix[10][10];

printf("Enter rows and column of matrix: ");
scanf("%d %d",&x,&y);
printf("Enter elements of matrix: ");
for(int i=0;i<(x);i++){
    for(int j=0;j<(y);j++){
        printf("Enter elements a%d%d:",i,j);
        scanf("%d",&no);
        arr[i][j]=no;
    }
}
printf("Entered Matrix: \n");
for(int i=0;i<(x);i++){
    for(int j=0;j<(y);j++){
        
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}
for(int i=0;i<(x);i++){
    for(int j=0;j<(y);j++){
        transpose_Matrix[j][i]=arr[i][j];
    }
}
printf("Transpose of Matrix: \n");
for(int i=0;i<(y);i++){
    for(int j=0;j<(x);j++){
        
        printf("%d ",transpose_Matrix[i][j]);
    }
    printf("\n");
}















}