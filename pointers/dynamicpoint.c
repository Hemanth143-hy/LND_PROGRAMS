#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
#if 1

int main()
{
	int i;
	int j;
	char *temp;
	char **ptr = ((char**) malloc (5*sizeof(char*)));
	for(i = 0; i < 5; i++) {
		ptr[i]=((char*) malloc (sizeof(char)));
	}
	printf("enter the names: \n");
	for(i = 0; i < 5; i++) {
		fgets(ptr[i],SIZE, stdin);
	*((ptr[i] + strlen(ptr[i])-1))='\0';
	}
	for(i = 0; i < 5; i++) {
		for(j = i+1; j < 5 ; j++) {
			if(*ptr[i] > *ptr[j]) {
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}  
	printf("\nsorted names are:\n");
	for(i = 0; i < 5; i++) {
		printf("%s\n", ptr[i]);
	}
	printf("\n");
	return 0;
}
#endif

