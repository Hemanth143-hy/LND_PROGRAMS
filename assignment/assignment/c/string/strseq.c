#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50
int* mysqu(char* );
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
int* mysqu(char* str)
{
	char *temp1;
	int count = 0;
	char *temp;
	temp = str;
	while(*str) {
		if(*str == *(str+1)) {
			temp1 = str;
			count++;
			if(count >0) {
				*str = *(str+1);
			}
			while(*str) {
				*str = *(str+1);
				*str++;
			}
			str= temp1;
		} else {
			*str++;
		}
	printf("%d\n", count);
	}
	return temp;
}
