#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//#include<stddef.h>
struct Node
{
        int id;
        char name[50];
        char lname[50];
        char gender[50];
        char occupation[50];
        int age;
        struct Node* next;
};
struct Node  *create(struct Node *head , FILE *fp);
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
        printList(head);
        fclose(fp);
        freelist(head);
        head = NULL;
        return 0;
}
struct Node *create(struct Node *head,  FILE *fp)
{
        struct Node mem;
		struct Node* temp = head;
        while (fscanf(fp, "%d %s %s %s %s %d", &mem.id, mem.name,mem.lname, mem.gender, mem.occupation, &mem.age) != EOF)  {
                struct Node* newNode;
             //   struct Node* temp = head;
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode -> id = mem.id;
                strcpy(newNode -> name, mem.name);
                strcpy(newNode->lname, mem.lname);
                strcpy(newNode -> gender, mem.gender);
                strcpy(newNode -> occupation, mem.occupation);
                newNode -> age = mem.age;
               // newNode -> next = head;
                if(head == NULL) {
					head = newNode;
					temp = newNode;
			//	head->next = head;
				} else {
					temp->next = newNode;
					temp = temp->next;
				}
		//	temp->next = head;
			}
	temp -> next = head;
	return head;
}
               	
void printList(struct Node *head)
{
       struct Node* temp= head;
        while (temp != NULL) {
        printf("%d\t", temp->id);
        printf("%-10s\t", temp->name);
        printf("%-10s\t", temp->lname);
        printf("%-10s\t", temp->gender);
        printf("%-10s\t", temp->occupation);
        printf("%d\n", temp->age);
		temp = temp->next;
		if(temp == head) {
			break;
		}
		}
        printf("\n");
       
}
void freelist(struct Node *head)
{
    struct Node *newNode = head;
    struct Node *temp;
    do {
    	temp = newNode;
        newNode = newNode -> next;
        free(temp);
        temp = NULL;
        } while (head != newNode);
}
