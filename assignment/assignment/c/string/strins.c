#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50
char *myinsert(char* str1 , const char c, int pos); 
int main()
{
	char* str1 = NULL;
	str1 = ((char*) malloc(SIZE * sizeof(char)));
	char c = ' ';
	int pos;
	fgets(str1 , SIZE ,stdin);	
	*(str1 + (strlen(str1)-1)) = '\0';
	printf("Enter the position  to insert:")
