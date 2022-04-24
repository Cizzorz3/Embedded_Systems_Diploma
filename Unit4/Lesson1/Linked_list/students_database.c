// FIXME complete the students database main function
#include "linked_lists.c"
void main(){
    char temp_text[40];
    while(1){
        printf("Choose one of the following \n");
        printf("1-Add student \n");
        printf("2-delete student \n");
        printf("3-view student \n");
        printf("4-delete_all \n");
        printf("5-Get the nth Node \n");
        printf("6-find_the_length_of_linked_list_by_iteration \n");
        printf("7-find_the_length_of_linked_list_by_recursion \n");
        printf("8-find_nth_node_from_the_end \n");
        printf("9-find the middle of the list \n");
        printf("10-reverse_linked_lsit \n");
        printf("============================== \n");
        printf("Enter option number \n");

        gets(temp_text);

        switch (atoi(temp_text))
        {
        case 1:
            Add_student();
            break;
        case 2:
            Delete_Student();
            break;
        case 3:
            view_Students();
            break;
        case 4:
            Delete_All();
            break;
        case 5:
            Get_nth_node();
            break;
        case 6:
            find_the_length_of_linked_list_by_iteration();
            break;
        case 7:
            printf("The length of the linked list : %d \n" , find_the_length_of_linked_list_by_recursion(First_Student_Head_Node));
            break;
        case 8:
            find_nth_node_from_the_end();
            break;
        case 9:
            find_middle_of_linked_list();
            break;
        case 10:
            reverse_linked_lsit();
            break;
        default:
            printf("wrong option");
            break;
        }




    }
}