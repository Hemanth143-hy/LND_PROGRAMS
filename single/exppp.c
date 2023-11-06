#include <stdio.h>
#include <stdlib.h>
struct node {
        int data;
        struct node* next;
};
struct node* head;
struct node* newnode;
struct node* temp;
void traverse(struct node* head);
int main() {
        int i;
        int num;
//        head = NULL;
    //    newnode  = (struct node*)malloc(sizeof(struct node));
        printf("enter the no of nodes to be created");
        scanf("%d" , &num);
        for(i = 0 ; i < num ; i++) {
			newnode  = (struct node*)malloc(sizeof(struct node));
			printf("enter the data:");
            scanf("%d" ,&newnode->data);
			newnode -> next = NULL;
        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp-> next = newnode;
            temp = newnode;
        }
	}
	traverse(head);
}
void traverse(struct node* head) {
        temp = head;
        while(temp != NULL) {
            printf("%d->" , temp->data);
            temp = temp->next;
        }
}
