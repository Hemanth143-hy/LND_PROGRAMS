#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
void sort(char**);
int main()
{
	int i;
//	int j;
//	char *temp;
	char **ptr = ((char**) malloc (5*sizeof(char*)));
	for(i = 0; i < 5; i++) {
		ptr[i]=((char*) malloc (10*sizeof(char)));
	}
	printf("enter the names: \n");
	for(i = 0; i < 5; i++) {
		fgets(ptr[i],SIZE , stdin);
	*((ptr[i] + strlen(ptr[i])-1))='\0';
	}
/*
	for(i = 0; i < 5; i++) {
		for(j = i+1; j < 5 ; j++) {
			if(*ptr[i] > *ptr[j]) {
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	} 
*/  
	sort(ptr);
	printf("\nsorted names are:\n");
	for(i = 0; i < 5; i++) {
		printf("%s\n", ptr[i]);
	}
	printf("\n");
	free(ptr);
	ptr = NULL;
	return 0;
}
void sort(char **ptr)
{
	int i;
	int j;
	char *temp;
	for(i = 0; i < 5; i++) {
 		for(j = i+1; j < 5 ; j++) {
			if(*ptr[i] > *ptr[j]) {
 				temp = ptr[i];
    			ptr[i] = ptr[j];
    			ptr[j] = temp;
   			}	
   		}	
 	}
}
