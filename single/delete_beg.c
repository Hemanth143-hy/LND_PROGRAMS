#include <stdlib.h>
#include<stdio.h>
struct node {
        int data;
        struct node *next;
};
struct node * head;
void Insert(int x);
void Print();
//struct node
void Delete_begining(struct node *head);
int main()
{
        int i;
        int num;
        int new;
    int x;
    head = NULL;
    printf("How many numbers?\n");
    scanf("%d", &num);
        for (i = 0; i < num; i++) {
                printf("Enter the number :\n");
            scanf("%d", &x);
            Insert(x);
			
		}
			Print();
			Delete_begining(head);
            Print();
	//	Delete_begining();
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
        struct node * temp= head;
        printf("List is :");
   //             temp = head;
        while (temp != NULL) {
                printf(" %d", temp -> data);
                temp = temp -> next;
        }
        printf("\n");
}
//struct node 
void Delete_begining(struct node *head)
{
//	struct node *head;
	if(head == NULL) {
		printf("The list is empty:");
		//exit(1);
	} else {
		struct node *ptr;
		head = ptr;
		head = ptr->next;
		//	head = ptr->next;
	//	free(ptr);
	
	//Print();
	printf("deletion of node is completed..");
	free(ptr);
	}
//	return head;
}
