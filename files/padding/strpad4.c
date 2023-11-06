#include<stdio.h>
#pragma packet(1)
struct hhhhd {
	int a : 17;
	short b:12;
	int c : 7;
	char d : 4;
	short f : 12;
	char g : 4;
	int h : 12;
	char l;
	}sd;
int main()
{
	printf("%ld",sizeof(sd));
}
