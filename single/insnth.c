#include <stdlib.h>
#include<stdio.h>
struct node {
        int data;
        struct node *next;
};
struct node * head;
void Insert(int x);
void Print();
void Insert_nth(int new, int position);
int main()
{
        int i;
    	int num;
		int position;
        int choice;
        int new;
    int x;
    head = NULL;
    printf("How many numbers?\n");
    scanf("%d", &num);
        for (i = 0; i < num; i++) {
                printf("Enter the number :\n");
            scanf("%d", &x);
            Insert(x);
                        Print();
        }
        printf("enter to node data to insert!:\n");
        scanf("%d",&new);
		printf("enter the position to insert data:\n");\
		scanf("%d",&position);
        Insert_nth(new ,  position );
        Print();
        while(choice) {
        printf("\nPress 0 to insert more:\n");
        scanf("%d",&choice);
                if(choice ==0) {
                        printf("enter the  number to insert again:");
                        scanf("%d",&new);
                        Insert_nth(new , position);
                        Print();
                } else {
                        exit(1);
        //void Print();
                        }
        }
}
void Insert(int x)
{
        struct node * temp = (struct node*) malloc(sizeof(struct node));
        temp -> data = x;
        temp -> next = head;
        head = temp;
}
void Print()
{
        struct node * temp = head;
        printf("List is :");
                temp = head;
        while (temp != NULL) {
                printf(" %d", temp -> data);
                temp = temp -> next;
        }
        printf("\n");
}
void Insert_nth(int new ,int position)
{
	struct node *newNode;
	newNode = malloc(sizeof(struct node));
	newNode->data = new;
	struct node *temp = head;
	for(int i = 1; i >= position -1 ; i++) {
  		if(temp->next != NULL) {
    		temp = temp->next;
  		}
	}
	newNode->next = temp->next;
	temp->next = newNode;
}
