#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
        int id;
        char name[50];
        char lname[50];
        char gender[50];
        char occupation[50];
        int age;
        struct Node* prev;
        struct Node* next;
};
struct Node  *create(struct Node *head , FILE *fp);
void Delete_alternate(struct Node *head);
void printList(struct Node *head);
void freelist(struct Node *head); 
int main()
{
        FILE *fp = NULL;
        struct Node* head = NULL;
        fp = fopen("Club_Membership_2020.txt", "r");
        if (fp == NULL)
        {
                printf("Error! Could not read the file.");
            exit(1);
        }
        head = create(head, fp);
		Delete_alternate(head);
        printList(head);
        fclose(fp);
        freelist(head);
        head = NULL;
        return 0;
}
struct Node *create(struct Node *head,  FILE *fp)
{
	struct Node mem;
    while (fscanf(fp, "%d %s %s %s %s %d", &mem.id, mem.name,mem.lname, mem.gender, mem.occupation, &mem.age) != EOF)  {
    struct Node* newNode;
    struct Node* temp = head;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> id = mem.id;
    strcpy(newNode -> name, mem.name);
    strcpy(newNode->lname, mem.lname);
    strcpy(newNode -> gender, mem.gender);
    strcpy(newNode -> occupation, mem.occupation);
    newNode -> age = mem.age;
    newNode -> next = NULL;
                        newNode -> prev = NULL;
                if(head == NULL) {
                        newNode->prev = NULL ;
                                        head = newNode;
//                                      return;
                } else {
                                while(temp->next != NULL) {
                                temp = temp->next;
                                }
                                temp->next = newNode;
                                newNode->prev = temp;
//                              return;
                        }
                }
        return head;
}
void printList(struct Node *head)
{
        struct Node* temp= head;
       if (temp == NULL) {
                printf("List is empty!");
        } else {
        while (temp != NULL) {
        printf("%d\t", temp->id);
        printf("%-10s\t", temp->name);
        printf("%-10s\t", temp->lname);
        printf("%-10s\t", temp->gender);
        printf("%-10s\t", temp->occupation);
        printf("%d\t", temp->age);
        temp = temp->next;
        printf("\n");
                }
        }
}
void freelist(struct Node *head)
{
        struct Node *temp;
        while(head != NULL) {
                temp = head;
                head =  head -> next;
                free(temp);
                temp = NULL;
        }
}
void Delete_alternate(struct Node *head) {
        if (head == NULL)
                return;
    struct Node *temp = head;
    struct Node *newNode = head -> next;
    while(temp != NULL && newNode != NULL) {
        temp -> next = newNode -> next;
        free(newNode);
        temp = temp -> next;
        if (temp != NULL)
        	newNode = temp -> next;
        }
}

