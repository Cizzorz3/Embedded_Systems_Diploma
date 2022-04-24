//@ Copyrights by Eng.Mohamed Adel
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

void Add_student ();
int Delete_Student();
void view_Students();
void Delete_All();
void Get_nth_node();
void find_the_index();
void find_the_length_of_linked_list_by_iteration();
int find_the_length_of_linked_list_by_recursion();
void find_nth_node_from_the_end();
void find_middle_of_linked_list();
void reverse_linked_lsit();

struct SData {
    int ID ;
    char name [40];
    float height ;
};

struct Sstudent
{
    struct SData data ;
    struct Sstudent * P_next_student ;
};

struct Sstudent * First_Student_Head_Node = NULL ;
//TODO completed the strcuture for the linked list



