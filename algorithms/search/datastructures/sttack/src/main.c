#include "header.h"
//int Top=-1,
inp_array[SIZE];
void Push();
void Pop();
void show();
int main()
{
        int choice;
        while(1)
        {
                printf("\nOperations performed by Stack");
                printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
                printf("\n\nEnter the choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: Push();
                                        break;
                        case 2: Pop();
                                        break;
                        case 3: show();
                                        break;
                        case 4: exit(0);

                        default: printf("\nInvalid choice!!");
                }
        }
}
