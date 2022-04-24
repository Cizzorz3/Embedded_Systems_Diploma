#include<stdio.h>
struct student {
    int roll ;
    char name[50];
    int marks ;
}s;
void main(){
    struct student arr[10];
    int i ;
    for(i=0;i<10;i++){
        printf("Enter information of students ");
        printf("For roll number ");
        scanf("%d",&s.roll);
        printf("Enter name: ");
        scanf("%s",&s.name);
        printf("Enter marks: ");
        scanf("%d",&s.marks);
        arr[i]= s;
    }
   for(i=0;i<10;i++){
       printf("Displaying information of students \n");
       printf("Information fr roll number %d \n",arr[i].roll);
       printf("Name: %s \n",arr[i].name);
       printf("Marks: %d \n",arr[i].marks);
   }

}