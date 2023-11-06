#include<stdio.h>
#include<stdlib.h>
struct Node {
	char data;
	struct Node* next;
	};
void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %c ", n->data);
        n = n->next;
    }
}
int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	head -> data = 'A';
	head ->next = second;
	second -> data = 'B';
	second ->next = third;
	third -> data = 'C';
	third ->next = NULL;
	printList(head);
	return 0;
}

