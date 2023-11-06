#include <stdio.h>
#include <stdlib.h>
struct node {
        int data;
        struct node * link;
};
struct node * head;
void Insert(int data, int pos);
void Print();
int data;
int pos;


int main()
{
        head = NULL;   //Intially the list is empty.
        int num;
        int x;
/*      Insert(2, 1);  //List : 2
        Insert(3, 2);  //List : 2, 3
        Insert(4, 1);  //List : 4, 2, 3
        Insert(5, 2);  //List : 4, 5, 2, 3
        Print();*/
        printf("How many numbers?\n");
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
                printf("Enter the number :\n");
                scanf("%d", &x);
        //      Insert(data, pos);
        //      Print();
        }
		
        Insert(data, pos);
        Print();



       return 0;
}
void Insert(int data, int pos)
{
    struct node * temp1 = (struct node*) malloc(sizeof(struct node));  // creating a malloc
        temp1 -> data = data;
        temp1 -> link = NULL;
        if (pos == 1) {
                temp1 -> link = head;
                head = temp1;
                return;
        }
        struct node * temp2 = head;
        for (int i = 0; i < pos - 2; i++) {
                temp2 = temp2 -> link;
        }
        temp1 -> link = temp2 -> link;
        temp2 -> link = temp1;
}
void Print()
{
        struct node * temp = head;
        while (temp != NULL) {
                printf(" %d ", temp -> data);
                temp = temp -> link;
        }
        printf("\n");
}
