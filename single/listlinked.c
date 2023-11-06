#include <stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	};
struct node *head;
struct node *temp;
void Insert_data(int x);
void Print_list();
void Insert_End(int new);
void Insert_beg(int new);
void Delete_begining();
void Delete_End();
void Delete_Pos();
int i;
int num;
int new;
int position;
int x;
int main()
{
	int ch;
	while(1) {
		printf("----->> select the operation to be performed <<-----\n");
		printf("\t 1  - Insert_data\n");
		printf("\t 2  - Print_List\n");
		printf("\t 3  - Insert_End\n");
		printf("\t 4  - Delete_Begin\n");
		printf("\t 5  - Delete_End\n");
		printf("\t 6  - Delete_Pos\n");
		printf("\t 7  - Insert_beg\n");
		printf("\t 8  - exit\n");
		printf("\nenter your choice:");
		scanf("%d",&ch);
		switch(ch) {
		case 1 :
				head = NULL;
				printf("How many numbers?\n");
				scanf("%d", &num);
				for(i = 0; i < num ; i++) {
					printf("Enter the number:");
					scanf("%d",&x);
					Insert_data(x);
				}
			break;
		case 2 :
			Print_list();
			break;
		case 3 :
			Insert_End(new);
			break;
		case 4 :
			Delete_begining();
			break;
		case 5 :
			Delete_End();
			break;
		case 6:
			Delete_Pos();
			break;
		case 7:
			Insert_beg(new);
			break;
		case 8 :
			exit(1);
			break;
		default :
			printf("The option is not available");
			}
	}

}
void Insert_data(int x)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if(head == NULL) {
	head = temp;
	} else {
	 struct node *q = head;
	 while (q->next != NULL) {
		q = q->next;
	}	
	q->next = temp;
	}
}
void Print_list()
{
	struct node *temp = head;
	printf("list is:");
	temp = head;
	while(temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void Insert_End(int new)
{
	printf("enter the data to insert!:\n");
	scanf("%d",&new);
	struct node *ptr = (struct node*)malloc(sizeof(struct node));	
	ptr->data = new;
	ptr->next = NULL;
	struct node *temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = ptr;
}			
void Insert_beg(int new)
{
	printf("enter the data to insert!:\n");
	scanf("%d",&new);
	struct node *ptr = (struct node*)malloc(sizeof(struct node));	
	ptr->data = new;
	ptr->next = NULL;
	struct node *temp = head;
	while(temp != NULL) {
		temp = temp->next;
	}
	ptr->next = head;
	head = ptr;
}			
void Delete_begining()
{
	struct node *ptr;
	if(head == NULL) {
		printf("The list is empty");
	} else {
		ptr = head;
		head = ptr->next;
		free(ptr);
	}
	printf("deletion is completed:");
}
void Delete_End()
{
	struct node *prev;
	struct node *new;
	temp = head;
	while( temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	free(temp);	
	printf("The List after delete of data:");
	new = head;
	while(new != NULL) {
		printf("%d\t",new->data);
		new = new->next;
	}
	printf("\n");
}
void Delete_Pos()
{ 
	printf("enter position to delete node:");
	scanf("%d",&position);
	temp = head;
	for(int i=0; i< position-1; i++) {
  		if(temp->next!=NULL) {
    		temp = temp->next;
  		}
	}
	temp->next = temp->next->next;
}
