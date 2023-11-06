#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct Node {
        int id;
    char name[50];
    char lname[50];
    char gender[50];
    char occupation[50];
    int age;
    struct Node* next;
};
struct Node *create(struct Node *, FILE *);
void printList(struct Node *);
void deleteAlt(struct Node *);
void freelist(struct Node *);
int main()
{
        FILE *fp = NULL;
    struct Node* head = NULL;
    fp = fopen("Club_Membership_2020.txt", "r");
    if (fp == NULL) {
                printf("Error! Could not read the file.");
        exit(1);
        }
    head = create(head, fp);
    deleteAlt(head);
    printList(head);
    fclose(fp);
    freelist(head);
    head = NULL;
    return 0;
}
struct Node *create(struct Node *head,  FILE *fp)
{
        struct Node mem;
    while (fscanf(fp, "%d %s %s %s %s %d", &mem.id, mem.name, mem.lname, mem.gender, mem.occupation, &mem.age) != EOF) {
                struct Node* newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->id = mem.id;
        strcpy(newNode->name, mem.name);
        strcpy(newNode->lname, mem.lname);
        strcpy(newNode->gender, mem.gender);
        strcpy(newNode->occupation, mem.occupation);
        newNode->age = mem.age;
        newNode->next = NULL;
        if(head == NULL) {
                        head = newNode;
        }
                else {
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
void deleteAlt(struct Node *head)
{
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
void printList(struct Node *head)
{
        if (head == NULL) {
                printf("List is empty!");
        }
        else {
                while (head != NULL) {
                        printf("%d\t", head->id);
            printf("%-20s\t", head->name);
            printf("%-20s\t", head->lname);
            printf("%-20s\t", head->gender);
            printf("%-20s\t", head->occupation);
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
        head =  head->next;
        free(temp);
        temp = NULL;
        }
}
