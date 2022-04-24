#include<stdio.h>
struct Student
{
    char name[50];
    int roll;
    double marks ;
};

void main(){
    struct Student s ;
    printf("Enter information of students: \n");
    printf("Enter name : ");
    scanf("%s",&s.name);
    printf("Enter roll number: ");
    scanf("%d",&s.roll);
    printf("Enter Marks: ");
    scanf("%lf",&s.marks);


   printf("Displaying information \n");
   printf("%s \n",s.name);
   printf("%d \n",s.roll);
   printf("%lf \n",s.marks);





}