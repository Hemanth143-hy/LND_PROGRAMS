#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50
char* mysqu(char* );
int main()
{
	char *str1;
	char *str = NULL ;
	str =((char*) malloc(SIZE * sizeof(char)));
	printf("Enter the string to squeze:");
	fgets(str , SIZE , stdin);
	*(str + (strlen(str)-1)) = '\0';
//	mysqu(str);
	printf("the squezed string is:%s",mysqu(str));
	free(str);
	str = NULL ;
}
* mysqu(char* str)
{
	
