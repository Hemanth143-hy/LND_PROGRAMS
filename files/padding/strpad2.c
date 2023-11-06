#include<stdio.h>
struct {
	char c :2;
	char a : 3;
	char b : 5;
	char d;
	} hh;
int main()
{
	printf("%ld",sizeof(hh));
}
