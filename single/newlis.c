#include<stdio.h>
#include<stdlib.h>
struct neww {
        char name[15];
		int age;
		float salary;
        struct neww* next;
        };
int main()
{
        struct neww* start;
        struct neww* mid;
      //  struct neww* end;
        start =malloc(sizeof(struct neww));
        mid =malloc(sizeof(struct neww));
       // end =malloc(sizeof(struct neww));
        start->name = "hemanth;
        start->age  = 12;
        start->sal = 160;
        start -> next = mid;
        mid -> next = NULL;
     //   end -> next = NULL;
        struct neww* temp;
        temp = start;
        while(temp != NULL) {
                printf("%s%d%f\t",start->name , start->age , start->sal);
                temp = temp->next;
        }
        return 0;
}
