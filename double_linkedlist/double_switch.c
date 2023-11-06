#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *prev;	
	struct node *next;
};
struct node *head;
struct node *Newnode;
struct node *Insert_data(int x);
void Print_List();
void Print_rev();
void Insert_Begining(int x);
int num;
int i;
int new;
int x;
int main() {
	int ch;
	while(1) {
		printf("------->> select the operation to be performed <<------\n");
		printf("\t 1 - Insert_data\n");
		printf("\t 2 - Print_List\n");
		printf("\t 3 - Printf_rev\n");
		printf("\t 4 - Insert_Begining\n");
		printf("\t 5 - exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch) {
		case 1 :
				head = NULL;
				printf("How many numbers?\n");
				scanf("%d",&num);
				for(i = 0; i < num ; i++) {
					printf("Enter the number:");
					scanf("%d",&x);
					struct node *ptr = Insert_data(x);
				if(head == NULL) {
					head = ptr;
				}
	
				}
			break;
		case 2 :
			Print_List();
			break;
		case 3 : 
			Print_rev();
			break;
		case 4 :
			Insert_Begining(x);
			break;
		case 5 :
			exit(1);
			break;
		default :
			printf("The option is not available");
			} 
		}
}
struct node  *Insert_data(int x)
{
	struct node *Newnode = (struct node*)malloc(sizeof(struct node));
	Newnode->data = x;
	Newnode->prev = NULL;
	Newnode->next = NULL;
	return Newnode;
}
void Insert_Begining(int x) {
	printf("enter the data to be inserted!:\n");
	scanf("%d",&new);
	struct node* head = Newnode;
	if(head == NULL) {
		head = Newnode;
		return ;
	} else  {
		head->prev = Newnode;
		Newnode->next = head;
		head = Newnode;
	}
}
void Print_List() {
	struct node* temp = head;
	printf("Forward:");
	while(temp != NULL) {
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void Print_rev() {
	struct node* temp = head;
	if(temp == NULL) return;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	printf("reverse:");
	while(temp != NULL) {
		printf("%d" , temp->data);
		temp = temp->prev;
	}
	printf("\n");
}	

