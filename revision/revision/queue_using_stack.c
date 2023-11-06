#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5
int stack1[CAPACITY];
int stack2[CAPACITY];
int topS1 = -1;
int topS2 = -1;
int count = 0;
int element;
void insert();
void delete();
void display();
void pushS1(int data);
void pushS2(int data);
int popS1();
int popS2();
void main ()
{
	int choice;
	while(1) {
		printf("\n1.Insert \n2.Delete  \n3.Display \n4.exit");
		printf("\nEnter your choice-");
		scanf("%d", &choice);
		switch (choice) {	
			case 1:
				printf("\nenter the element-");
				scanf("%d", &element);	
				insert(element);
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nEnter valid choice\n");                 
		 }
	}
} 
void insert(int x) 
{
	pushS1(x);
	count++;
} 
void pushS1(int data)
{
	if(topS1 == CAPACITY - 1) {	
		printf("\nqueue is full ");
	} else {
		topS1++;
		stack1[topS1] = data;
	}
}
void pushS2(int data)
{
	if(topS2 == CAPACITY - 1) {
		printf("\nqueue is full ");
	} else {
		topS2++;
		stack2[topS2] = data;
	}
}
void delete()
{
	int i, a, b;
	if(topS1 == -1 && topS2 == -1) {
		printf("\nqueue is empty");
	} else {
		for(i = 0; i < count; i++) {
			a=popS1();
			pushS2(a);
		}
		b = popS2();
		printf("\ndeleted element %d-", b);
		count--;
		for(i = 0; i < count; i++) {
			a=popS2();
			pushS1(a);
		}
	}
}
int popS1()
{
	return stack1[topS1--];
}
int popS2()
{
	return stack2[topS2--];
}
void display()
{
	int i;
	for(i = 0; i <= topS1; i++) {
		printf("\t%d", stack1[i]);
	}
}
