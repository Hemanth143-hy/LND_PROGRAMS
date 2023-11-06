#include<stdio.h>
#include<stdlib.h>
struct first {
	int data;
	struct first* next;
	};
struct first *temp , *head , *New;
void create();
void display();
int main() 
{
//	struct  first* temp ;
//	struct first* head ;
//	struct first*  New ;
//	temp = (struct first*)malloc(sizeof(struct first));
	int choice;
	printf("1 - create\n");
	printf("2 - display\n");
	printf("3 - exit\n");
	printf("enter your choice :\n");
	scanf("%d",&choice); 
	switch(choice) {
	case 1:
		head = NULL;
		create();
		break;
	case 2 :
		display();
		break;
	case 3 :
		exit(1);
		break;
	}
}
void create()
{
	struct first* temp;
	struct first* head;
	int in;
	temp = ((struct first*)malloc(sizeof(struct first)));
	head = ((struct first*)malloc(sizeof(struct first)));
	printf("enter the num:");
	scanf("%d",&in);
	temp->data = in;
	if(head == NULL) {
		temp->next = head;
		head = temp;	
	 } else {
		head->next = temp;
		while(temp != NULL) {
			New = temp -> next;
			}
			New = temp;
	}
}
void display() 
{
	struct first *temp;
	temp = head;
	while(temp != NULL) {
		printf("%d",temp->data);
		}
		temp = temp -> next;
	printf("\n");
}
		
 
			
		
