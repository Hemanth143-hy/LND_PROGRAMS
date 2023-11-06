#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void delete_nth_node();

struct node {
	int data;
	struct node* next;
};
struct node* head;
struct node* newnode;
struct node* temp;

int main() {
	int choice;
	head = NULL;
	int num;
	int i = 0;	
	while(1) {
		printf("\n1 : insertion\n2 : Display\n3 : Delete_nth_node\n4 :exit\n");
		printf("enter your choice:");
		scanf("%d" , &choice);
		switch(choice) {	
			case 1 :
				printf("enter the no of nodes:");
				scanf("%d" ,&num);
				newnode = ((struct node*)malloc(sizeof(struct node)));
				for(i = 0; i < num; i++) {
				//	newnode = ((struct node*)malloc(sizeof(struct node)));
					printf("enter the data:");
					scanf("%d" , &newnode->data);
					newnode->next = NULL;
					create();
				}
				break;
			case 2 :
				display();
				break;
			case 3 :
				delete_nth_node();
				break;
			case 4 :
				exit(1);
				break;
			default :
				printf("your option is wrong:");
		}
	}
}
void create() {	
/*	struct node* newnode;
	struct node* temp;
	int num;
	int i =0;
	printf("enter the no of nodes:");
	scanf("%d" ,&num);
	for(i = 0; i < num; i++) {
		newnode = ((struct node*)malloc(sizeof(struct node)));
		printf("enter the data:");
		scanf("%d" , &newnode->data);
		newnode->next = NULL;
	}*/
	if(head == NULL) {
		head =temp = newnode;
	} else {
//		temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
	}

}
void delete_nth_node() {
	int pos;
	printf("enter the position to delete");
	scanf("%d" , &pos);
	if(head->next == NULL) {
		head = NULL;
	} else {
		struct node* prev;
		struct node* temp;
		temp = head;
		while(temp -> next == pos-1) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;	
		free(temp);
		temp = NULL;
	}

}
void display() {
	int i = 0;
	struct node* temp;
	temp = head;
	while(temp != NULL) {	
		printf("%d"  ,temp->data);
		temp = temp->next;
	}
	printf("\n");
}
