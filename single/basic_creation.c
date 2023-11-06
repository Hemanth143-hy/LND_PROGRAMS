#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
	};
int main()
{
	int i;
	int n;
	struct Node*  head;
	struct Node*  temp;
	head = NULL;
	temp = (struct Node*)malloc(sizeof(struct Node));
	printf("enter the numbers to enter:");
	scanf("%d",&n);
	for(i = 0; i < n ; i++) {
	printf("enter the data:");
	scanf("%d",temp->data);
		temp->next = NULL;
	if(head == NULL) {
		head = temp ;
	} else {
		struct Node* new ;
			new = head;
		while(new != NULL) {
	       new = new->next;
			}
		temp = new->next;
		}
	}
	while(head != NULL) {
		printf("%d",head->data);
		}
	head = head->next;
}
	
