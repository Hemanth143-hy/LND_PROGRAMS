#include<stdio.h>
#pragma pack(1)
struct file {
	short int a;
	int h : 23;
	char c;
	short int d : 10;
	short int r : 12;
	} q;
int main()
{
	printf("%ld",sizeof(q));
}
