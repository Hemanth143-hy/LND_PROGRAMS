#include<stdio.h>
#pragma pack(1)
struct {
	char a;
	short int b :12;
	char d;
	int e : 20;
	char h : 2;
	} A;
int main()
{
	printf("%ld",sizeof(A));
}
