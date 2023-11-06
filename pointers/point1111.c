#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **ptr = ((int**)malloc(sizeof (int*)));
	 *ptr = (int*) malloc(sizeof (int));
	 **ptr = 10;
	printf("%d\n",ptr);
	printf("%u\n",sizeof(ptr));
	printf("%d\n",*ptr);
	printf("%u\n",sizeof(*ptr));
	printf("%d\n",**ptr);
	printf("%u\n",sizeof(**ptr));
}
