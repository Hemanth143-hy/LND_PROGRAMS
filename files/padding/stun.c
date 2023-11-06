#include<stdio.h>
#include<string.h>
struct demo {
	int i : 2;
	int j : 2 ;
	} dd;
int main() {
	int i ,j;
	dd.i = 2;
	dd.j = 1;
//	printf("%ld",sizeof(i));
//	printf("%ld",sizeof(j));
	printf("%ld",sizeof(dd));
}
