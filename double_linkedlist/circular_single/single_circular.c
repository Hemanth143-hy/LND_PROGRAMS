#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	}*new ,*head , *tail , *temp;
struct node *head;
void Create_List(int x);
void Print_List();
void Insert_begining();
void Insert_end();
void Insert_pos();
void Delete_begining();
void Delete_end();
void Delete_pos();
int num;
int val;
int x;
int pos;
int i ;
int main()
{
	int ch;
	while(1) {
		printf("----> select the operation to be performed <<---\n");
		printf("\t 1 - Create_List\n");
		printf("\t 2 - Print_List\n");
		printf("\t 3 - Insert_begining\n");
		printf("\t 4 - Insert_end\n");
		printf("\t 5 - Insert_pos\n");
		printf("\t 6 - Delete_begining\n");
		printf("\t 7 - Delete_end\n");
		printf("\t 8 - Delete_pos\n");
		printf("\t 9 - Exit\n");
		printf("\n Enter your choice:");
		scanf("%d", &ch);
		switch(ch) {
		case 1 :
				head = NULL;
				printf("How many numbers?");
				scanf("%d", &num);
				for(i = 0; i < num ; i++) {	
					printf("Enter the number :");
					scanf("%d", &x);
					Create_List(x);
				}
				break;	
		case 2 :
				if(head == NULL) {
					printf("the listt is empty");
				} else  {
				Print_List();
				}
				break;
		case 3 :
				Insert_begining();
				break;
		case 4 :
				Insert_end();
				break;
		case 5 :
				Insert_pos();
				break;
		case 6 :
				Delete_begining();
				break;
		case 7 :
				Delete_end();
				break;
		case 8 :
				Delete_pos();
				break;
		case 9 :
				exit(1);
				break;
		defalut :
				printf("the option is not available");
				exit(1);
				}
	}
}
void Create_List(int x) {
	new = (struct node*)malloc(sizeof(struct node));
	new->data = x;
	new->next = NULL;
	if(head == NULL) {
		head = new;
		tail = new;
	} else {
		tail->next = new;
		tail =  new;	
		tail->next = head;
   	}
}
void Create_List(int x) {
	new = (struct node*)malloc(sizeof(struct node));
	new->data = x;
	new->next = NULL;
	if(head == NULL) {
		head = new ;
		new->next = head;
	} else {
		temp = head;		
		while(temp->next != head) {
			temp = temp->next;
		}
		temp->next = new;
		new->next = head;
	}
}
void Print_List() {	
	struct node *temp = head;
	while(temp->next != head) {
		 printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("%d",temp->data);
	printf("\n");
}
void Insert_begining() {
//	new = (struct node*)malloc(sizeof(struct node));
	printf("enter the number to insert:");
	scanf("%d",&val);
	new->data = val;
	new->next = head;
	tail->next = new;
	head = new;
}
void Insert_end() {	
	printf("enter the number to insert:");
	scanf("%d",&val);
	new->data = val;
	tail->next = new;
	new->next = head;
	tail = new ;
}
void Insert_pos() {
	new = (struct node*)malloc(sizeof(struct node));
	printf("enter the value to insert in the link:");
	scanf("%d", &val);
	printf("enter the position to insert:");
	scanf("%d", &pos);
	temp = head;
	for(i = 0 ; i <pos-1 ; i++) {
		temp = temp->next;
		
	}
	new->data = val;
	new->next = temp->next;
	temp->next = new;
}
void Delete_begining() {	
	if(head == NULL) {
		printf("the list is empty");
	} else {
		temp = head;
		head = temp->next;
		tail->next = head;
	}
}
void Delete_end() {
	if(head == NULL) {
		printf("The list is empty");
	} else {
		temp = head;
		while(temp->next != head) {
				tail = temp;
				temp = temp->next;
		}
		tail->next = head;
	}
}
void Delete_pos() {
	printf("enter the poition :");
	scanf("%d",&pos);
	temp = head;
	for( i = 0 ; i < pos-1; i++) {
		temp = temp->next;
	}
	temp->next = temp->next->next;
}
