#include <stdio.h>
#include <stdlib.h>
struct node {
        int data;
        struct node *prev;
        struct node *next;
};
void display(struct node *);
struct node *create_node();
struct node *create_list(struct node *);
int count_node(struct node *);
struct node *insert_first(struct node *);
struct node *insert_end(struct node *);
struct node *insert_pos(struct node *);
struct node *del_first(struct node *);
struct node *del_last(struct node *);
struct node *del_pos(struct node *);
int main()
{
        struct node *head = NULL;
        int ch;
        while (1) {
          //      printf("\n************************** \n");
                printf(" --->> Double linked list operation <<---\n");
                printf("1. Print Double linked list \n");
                printf("2. Create Linked list \n");
                printf("3. Insert node at begin \n");
                printf("4. Insert node at end position \n");
                printf("5. Insert node at specific position \n");
                printf("6. Delete first node \n");
                printf("7. Delete last node \n");
                printf("8. Delete node specific position \n");
                printf("9. Exit \n");
//                printf("############################ \n");
              //taking input for choice
                printf("Enter the choice: ");
                scanf("%d", &ch);
               switch(ch) {
                       //Display list
                        case 1:
                                display(head);
                                int c = count_node(head);
                                printf("%d", c);
                                break;
                       //Create no of node
                        case 2:
                                head = create_list(head);
                                break;
                       //add node begin
                        case 3:
                                head = insert_first(head);
                                break;
                       //add node end position
                        case 4:
                                head = insert_end(head);
                                break;
                       //Insert node nth position
                        case 5:
                                head = insert_pos(head);
                                break;
                       //Delete first node
                        case 6:
                                head = del_first(head);
                                break;
                       //Delete last node
                        case 7:
                                head = del_last(head);
                                break;
                       //Delete node nth position
                        case 8:
                                head = del_pos(head);
                                break;
                        //Exit
                        case 9:
                                exit(0);
                       default:
                                printf("Enter wrong choice \n");
               }
        }
        free(head);
        head = NULL;
        return 0;
}
struct node *del_pos(struct node *head)
{
		int index = 0;
		int pos = 0;
        int count = 0;
       //call function for count node
        count = count_node(head);
       //taking position
        printf("Enter the delete position: ");
        scanf("%d", &pos);
       struct node *temp = head;
        struct node *ptr = NULL;
        //check list is empty or not
        if (head == NULL) {
                printf("List is empty \n");
       }
        //check position present in zise of list
        if(count > pos) {
                if (pos == 0) {
                        head = del_first(head); //If delete node is first node
                        return head;
                }
               for (index = 0; index < pos; index++) {
                        temp = temp->next;
                }
                //If delete node is last node
                if (temp->next == NULL) {
                        head = del_last(head);
                        return head;
                } else {
                        //temp of prev assign ptr
                        ptr= temp->prev;
                       //update next node
                        ptr->next = temp->next;
                        //Update previous node
                        temp->next->prev = ptr;
                        free(temp);
                        temp = NULL;
                        printf("Node deleted \n");
                       return head;
                }
        } else {
                printf("invalid position %d less element \n", pos);
        }
        return head;
}
//Delete last node
struct node *del_last(struct node *head)
{
        if (head == NULL) {
                printf("List is empty \n");
        } else if (head->next == NULL) {
                head = NULL; //if only one node present
                free(head);
                head = NULL;
       } else {
                struct node *temp = head;
                //Read upto last ndoe
                while (temp->next != NULL) {
                        temp = temp->next;
                }
                //previous last node assign null
                temp->prev->next = NULL;
                free(temp);
                temp = NULL;
               printf("Delete last node \n");
                return head;
       }
        return head;
}
//Delete first node
struct node *del_first(struct node *head)
{
        if (head == NULL) {
                printf("List is empty \n");
        } else if (head->next == NULL) {
                head = NULL; //if only one node present
                free(head);
       } else {
                struct node *temp = head;
                head  = head->next;
                head->prev = NULL;
                free(temp);
                temp = NULL;
                printf("First node deleted \n");
                return head;
        }
        return head;
}
//Count node
int count_node(struct node *head)
{
        int count = 0;
        while (head != NULL) {
                head = head->next;
                count++;
        }
        return count;
}
struct node *insert_pos(struct node *head)
{
        struct node *ptr;
        //create node
        ptr = create_node();
        int index;
        int pos;
        int count;
        //call function for count node
        count = count_node(head);
       //taking position
        printf("Enter the position to insert node: ");
        scanf("%d", &pos);
       if (pos == 0) {
       //if list is empty
                if (head == NULL) {
                        head = ptr;
               }/* else {
                        ptr->next = head;
                        head->prev = ptr;
                        head = ptr;
                }*/
       } else if (count > pos){
                struct node *temp = head;
                for (index = 0; index < pos - 1; index++) {
                       temp = temp->next;
               }
                // assign prev and next to new node
                ptr->prev = temp;
                ptr->next = temp->next;
               //link new node and old previous node
                temp->next = ptr;
               //link new node and next node
                ptr->next->prev = ptr;
       } else {
                printf("%d less then element \n", pos);
        }
       return head;
}
struct node *insert_first(struct node *head)
{
       struct node *ptr;
        //call create node function
        ptr =create_node();
       //if list is empty
        if (head == NULL) {
                head = ptr;
        } else {
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
        }
       return head;
}
struct node *create_list(struct node *head)
{
        int num;
        int index;
        struct node *ptr;
        //taking no of node
        printf("Enter the no of node: ");
        scanf("%d", &num);
        for (index = 0; index < num; index++) {
                //node create
                ptr = create_node();
                //check list is empty or not
                if (head == NULL) {
                        head = ptr;
                } else {
                        struct node *temp = head;
                        while (temp->next != NULL) {
                                temp = temp->next;
                       }
                       //link 2 node
                        temp->next = ptr;
                        ptr->prev = temp;
                }
       }
        return head;
}
struct node *create_node()
{
        int ele;
        struct node *new_node;
        //Allocate memory for node
        new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL) {
                printf("Memory can't be created \n");
                return NULL;
        }
        printf("Enter the element: ");
        scanf("%d", &new_node->data);
        new_node->prev = NULL;
        new_node->next = NULL;
       return new_node;
}
//Print list
void display(struct node *head)
{
        struct node *ptr;
        //Check list is empty or not
        if (head == NULL) {
                printf("List is empty \n");
        } else {
                //List print forword direction
                printf("Forword List is: ");
                while (head != NULL) {
                        printf("%d ", head->data);
                        ptr = head;
                        head = head->next;
                }
                printf("\n");
               //List print backword direction
                printf("Backwor list is: ");
                while (ptr != NULL) {
                        printf("%d ", ptr->data);
                        ptr = ptr->prev;
                }
                printf("\n");
        }
}
struct node *insert_end(struct node *head)
{
        struct node *ptr;
        //node create
        ptr = create_node();
       //check list is empty or not
        if (head == NULL){
                head = ptr;
       } else {
                //to read list
                struct node *temp = head;
                while (temp->next != NULL) {
                        temp = temp->next;
                }
                ptr->prev = temp;
               temp->next = ptr;
        }
        return head;
}
