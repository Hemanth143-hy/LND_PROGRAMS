#include<stdio.h>
int main()
{
	int num1 = 5;
	int num2 = 7;
	int *ptr1;
	int *ptr2;
	ptr1 = &num1;
	ptr2 = &num2;
	printf("%d" ,ptr1-ptr2);
//	printf("%d" ,ptr1+ptr2);
//	printf("%d" ,ptr1*ptr2);
//	printf("%d" ,ptr1/ptr2);
}

