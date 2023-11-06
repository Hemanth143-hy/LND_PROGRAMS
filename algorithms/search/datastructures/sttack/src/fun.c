#include"header.h"
int inp_array[SIZE];
void Push()
{
        int x;
        if(Top==SIZE-1)
        {
                printf("\nOverflow!!");
        }
        else
        {
                printf("\nEnter element to be inserted to the stack:");
                scanf("%d",&x);
                Top=Top+1;
                inp_array[Top]=x;
        }
}
void Pop()
{
        if(Top==-1)
        {
                printf("\nUnderflow!!");
        }
        else
        {
                printf("\nPopped element:  %d",inp_array[Top]);
                Top=Top-1;
        }
}
void show()
{
        if(Top==-1)
        {
                printf("\nUnderflow!!");
        }
        else
        {
                printf("\nElements present in the stack: \n");
                for(int i=Top;i>=0;--i)
                        printf("%d\n",inp_array[i]);
        }
}

