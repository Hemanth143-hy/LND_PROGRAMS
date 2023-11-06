#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct Node {
    int ID;
    char name[50];
    char lname[50];
    char gender[50];
    char occupation[50];
    int age;
    struct Node* next;
};
struct Node *create(struct Node *head,  FILE *fp);
void sortList(struct Node *head);
void printList(struct Node *head);
void freelist(struct Node *head);
int main()
{
        FILE *fp = NULL;
    struct Node* head = NULL;
    fp = fopen("Club_Membership_2020.txt", "r");
    if (fp == NULL) {
                printf("Error! Could not read the file.");
        exit(1);
    }
    head = create(head,fp);
    sortList(head);
    printList(head);
    fclose(fp);
    freelist(head);
    head = NULL;
    return 0;
}
struct Node *create(struct Node *head,  FILE *fp)
{
        struct Node mem;
    while (fscanf(fp, "%d %s %s %s %s %d", &mem.ID, mem.name, mem.lname, mem.gender, mem.occupation, &mem.age) != EOF) {
        struct Node* newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->ID = mem.ID;
        strcpy(newNode->name, mem.name);
        strcpy(newNode->lname, mem.lname);
        strcpy(newNode->gender, mem.gender);
        strcpy(newNode->occupation, mem.occupation);
        newNode->age = mem.age;
        newNode->next = NULL;
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
// Sorting the node according to the name
void sortList(struct Node *head)
{
        if (head != NULL) {
                struct Node *curr, *prev;
        int swapped;
        curr = head;
        while (curr->next != NULL) {
                        swapped = 0;
            while (curr->next != NULL) {
                                if (strcmp(curr->name, curr->next->name) > 0) {
                                        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
                    strcpy(temp->name, curr->name);
                    strcpy(temp->lname, curr->lname);
                    temp->ID = curr->ID;
                    strcpy(temp->gender, curr->gender);
                    strcpy(temp->occupation, curr->occupation);
                    temp->age = curr->age;
                                        strcpy(curr->name, curr->next->name);
                    strcpy(curr->lname, curr->next->lname);
                    curr->ID = curr->next->ID;
                    strcpy(curr->gender, curr->next->gender);
                    strcpy(curr->occupation, curr->next->occupation);
                    curr->age = curr->next->age;
                                        strcpy(curr->next->name, temp->name);
                    strcpy(curr->next->lname, temp->lname);
                    curr->next->ID = temp->ID;
                    strcpy(curr->next->gender, temp->gender);
                    strcpy(curr->next->occupation, temp->occupation);
                    curr->next->age = temp->age;
                                        free(temp);
                    swapped = 1;
                        }
                        prev = curr;
                        curr = curr->next;
                }
        if (swapped == 0) {
                        break;
        }
        curr = head;
        }
}
}
// Function to print the list
void printList(struct Node *head)
{
        if (head == NULL) {
                printf("List is empty!");
    } else {
                while (head != NULL) {
                printf("%d\t", head->ID);
            printf("%-10s\t", head->name);
            printf("%-10s\t", head->lname);
            printf("%-10s\t", head->gender);
            printf("%-10s\t", head->occupation);
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
        head = head->next;
        free(temp);
        temp = NULL;
    }
}
