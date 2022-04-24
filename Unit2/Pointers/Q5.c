#include<stdio.h>

struct Employee
{
  //  char Employe_Name[50];
    char *Employee_Name;
    int Employee_ID;
}emp1;


void main(){

 struct Employee emp1 ={"Alex",1002} ;
 struct Employee (*arr[])={&emp1};
 struct Employee (*(*p)[1])=&arr;
 printf("%s",(**(*p+1)).Employee_Name);
 printf("%d",(*(*p+1))->Employee_ID);

 





}