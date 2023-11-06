#include <stdio.h>
#include <string.h>
void* my_memcpy(void*, void*, int );
int main ()
{
	int a = 10;
	char *b;
	my_memcpy(b, &a, 13);
	printf("%d", *b);
	//printf("%d", *res);
//      int *res =(int *) memcpy(b, &a, 13);
//      printf("%d", *b);
//      printf("%d", *res);
}
void* my_memcpy(void* dest, void* src, int num )
{
	char *temp1 =(char* ) dest;
	char *temp2 =(char* ) src;
	while(num) {
		*temp1 = *temp2;
		temp1++;
		temp2++;
		num--;
	}
	return dest;
}
