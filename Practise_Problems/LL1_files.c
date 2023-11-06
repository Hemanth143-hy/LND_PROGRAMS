#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stddef.h>
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
struct Node  *create(struct Node *head, FILE *fp);
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
        while (fscanf(fp, "%d %s %s %s %s %d", &mem.id, mem.name,mem.lname, mem.gender, mem.occupation, &mem.age) != EOF)  {
                struct Node* newNode;
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode -> id = mem.id;
                strcpy(newNode -> name, mem.name);
                strcpy(newNode->lname, mem.lname);
                strcpy(newNode -> gender, mem.gender);
                strcpy(newNode -> occupation, mem.occupation);
                newNode -> age = mem.age;
                newNode -> next = NULL;
                if(head == NULL) {
                        head = newNode;
                } else {
                        struct Node *temp = NULL;
                        temp = head;
                        while(temp->next != NULL) {
                                temp = temp->next;
                        }
                        temp->next = newNode;
                  }
        }
        return head;
}
void printList(struct Node *head)
{
       if (head == NULL) {
                printf("List is empty!");
        } else {
        while (head != NULL) {
        printf("%d\t", head->id);
        printf("%s\t", head->name);
        printf("%s\t", head->lname);
        printf("%s\t", head->gender);
        printf("%s\t", head->occupation);
        printf("%d\t", head->age);
        head = head->next;
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
