#include <stdlib.h>
#include<stdio.h>
struct node {
        int data;
        struct node *next;
};
struct node * head;
void Insert(int x);
void Print();
void Insert_begining(int new);
int main()
{
	int i;
    int num;
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
	Insert_begining(new);
	Print();
	while(choice) {
	printf("\nPress 0 to insert more:\n");
	scanf("%d",&choice);
		if(choice ==0) { 
			printf("enter the  number to insert again:");
			scanf("%d",&new);
			Insert_begining(new);
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

void Insert_begining(int new)
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = new;
	ptr->next = NULL;
	struct node *temp = head;
	while(temp->next != NULL){
  		temp = temp->next;
	}	
	temp->next = ptr;
}
