#include<stdio.h>
#include<stdlib.h>
struct neww {
	int data;
	struct neww* next;
	};
int main()
{
	struct neww* start;
	struct neww* mid;
	struct neww* end;
	start =malloc(sizeof(struct neww));
	mid =malloc(sizeof(struct neww));
	end =malloc(sizeof(struct neww));
	start -> data =10;
	mid -> data = 20;
	end -> data = 40;
	start -> next = mid;
	mid -> next = end;
	end -> next = NULL;
	struct neww* temp;
	temp = start;
	while(temp != NULL) {
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	return 0;
}
