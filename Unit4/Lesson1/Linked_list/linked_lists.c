#include "linked_lists.h"
//APIS
// FIXME Complete THE APIS Implementation
// COMPLETED ADD student API completed
void Add_student (){
    char temp_text[40];
    struct Sstudent * new_student ;
    struct Sstudent * last_student ;

    // Check if the list is Empty
    if(First_Student_Head_Node==NULL){
        //Yes ??

        //Create Record
        new_student = (struct Sstudent *) malloc(sizeof(struct Sstudent));

        //Head Node Points to the first Node 
        First_Student_Head_Node = new_student ;

    }
    else {
        //No
        last_student = First_Student_Head_Node;
        //Navigate till you reach the last record 
        while(last_student->P_next_student!=NULL){
            last_student = last_student->P_next_student ;
        }
        //create new record
        new_student = (struct Sstudent *) malloc(sizeof(struct Sstudent));

        //last node pointing to null
        last_student->P_next_student = new_student ;

    }

    //Assign The values
    printf("Enter the ID \n");
    gets(temp_text);
    new_student->data.ID = atoi(temp_text);
    printf("Enter your Name \n");
    gets(new_student->data.name);
    printf("Enter your Height \n");
    gets(temp_text);
    new_student->data.height = atof(temp_text);

    

    new_student->P_next_student = NULL;
}

// TODO Complete Delete Student API
int Delete_Student(){
    char temp[50];
    unsigned int selected_id ;
    
    //Get the selected ID from the user
    printf("Enter the ID to be deleted \n");
    gets(temp);
    selected_id=atoi(temp);
    //check if the list is not empty
    if(First_Student_Head_Node!=NULL){
        struct Sstudent * student_to_be_deleted = First_Student_Head_Node ;
        struct Sstudent * Previous_student = NULL ;
        //Loop on all the records 
        while(student_to_be_deleted!=NULL)
        {
            //check if the selected id is the same
            if(student_to_be_deleted->data.ID== selected_id){
                //YES
                if(Previous_student!=NULL)
                {
                    Previous_student->P_next_student = student_to_be_deleted->P_next_student;
                }
                else 
                {
                    First_Student_Head_Node = student_to_be_deleted->P_next_student;
                }
                free(student_to_be_deleted);
                return 1;
            }
            //Loop through the whole list
            Previous_student = student_to_be_deleted ;
            student_to_be_deleted = student_to_be_deleted->P_next_student;
           
        }

    }
    printf("Can't Find the ID selected \n");
    return 0;
}
// TODO Complete view_Student API
void view_Students(){
    struct Sstudent * current_student = First_Student_Head_Node ;
    int count =1;
    if(First_Student_Head_Node!=NULL){
        while(current_student!=NULL){
            printf("Record Number :  %d \n",count);
            printf("ID :  %d \n ",current_student->data.ID);
            printf("Height :  %f \n",current_student->data.height);
            printf("Name :  %s \n",current_student->data.name);
            printf("============================= \n");
            current_student = current_student->P_next_student ;
            count++;
        }
    }
    else{
        printf("The list is empty \n");
    }


}
// TODO Complete Delete_All API
void Delete_All(){
    struct Sstudent * current_student = First_Student_Head_Node ;
    if(First_Student_Head_Node!=NULL){
        while(current_student!=NULL){
            struct Sstudent * temp_student = current_student;
            current_student = current_student->P_next_student ;
            free(temp_student);
        }
        First_Student_Head_Node = NULL;
    }
    else {
        printf("The list is empty \n");
    }
}
// TODO Complete count_nodes_no API
 void Get_nth_node(){
    unsigned int index_selected ;
    char temp [40];
    int count = 0 ;
    struct Sstudent * current_student = First_Student_Head_Node ;
    printf("Enter the index to be searched \n");
    gets(temp);
    index_selected = atoi(temp);
    if(First_Student_Head_Node!=NULL){
        while(count != index_selected){
            current_student = current_student->P_next_student;
            count++;
        }
        printf("The ID of the selected index is : %d \n",current_student->data.ID);
    }
 }
// // TODO Complete find_the_index API
 void find_the_length_of_linked_list_by_iteration(){
     int count = 0 ;
    struct Sstudent * current_student = First_Student_Head_Node ;
    if(First_Student_Head_Node != NULL){
        while(current_student !=NULL){
            current_student = current_student->P_next_student;
            count++;
        }
        printf("The length of the linked list is : %d \n",count);
    }

 }
// // TODO Complete find_nth_from_last_index API
 int find_the_length_of_linked_list_by_recursion(struct Sstudent * First_Student_Head_Node){
    if(First_Student_Head_Node==NULL){
        return 0;
    }
    else {
        return 1 + find_the_length_of_linked_list_by_recursion(First_Student_Head_Node->P_next_student);
    }
 }

 void find_nth_node_from_the_end(){
     int node ;
     char temp[40];
     printf("enter the n node \n");
     gets(temp);
     node=atoi(temp);
    int count = 0 ;
    struct Sstudent * current_student = First_Student_Head_Node ;
    if(First_Student_Head_Node != NULL){
        while(current_student !=NULL){
            current_student = current_student->P_next_student;
            count++;
        }
    printf("The nth node from the end is : %d \n",count-node+1);
 }
 }
// // TODO Complete find_middle_of_linked_list API
void find_middle_of_linked_list(){
    struct Sstudent * fast_ptr = First_Student_Head_Node ;
    struct Sstudent * slow_ptr = First_Student_Head_Node ;
    if(First_Student_Head_Node != NULL){
        while(fast_ptr !=NULL && fast_ptr->P_next_student!=NULL){
           fast_ptr= fast_ptr->P_next_student->P_next_student;
           slow_ptr=slow_ptr->P_next_student;
        }
    printf("The middle ID of the linked list is %d \n",slow_ptr->data.ID);
}
}
// // TODO Complete reverse_linked_lsit API
void reverse_linked_lsit(){
    struct Sstudent * current_student = First_Student_Head_Node ;
    struct Sstudent * next_student = NULL;
    struct Sstudent * Previous_student = NULL;
    while(current_student!=NULL){
        next_student = current_student->P_next_student;
        current_student->P_next_student = Previous_student ;
        Previous_student = current_student ;
        current_student = next_student ;
    }
    First_Student_Head_Node =Previous_student;

    
}
