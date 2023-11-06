#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
int change_spa1(char *str , char *str1);
int main() 
{
	int count = 0;
	char *str;
	str =((char*)malloc (SIZE * (sizeof(char))));
	printf("enter the first string:");
	fgets(str , SIZE , stdin);
		*(str + (strlen(str)-1)) = '\0';
	char *str1;
	str1 = ((char*) malloc (SIZE * (sizeof(char))));
	printf("Enter the second string to compare:");
	fgets(str1 , SIZE , stdin);
		*(str + (strlen(str) -1)) = '\0';
	count = change_spa1(str , str1);
	printf("%d",count);
	return 0;
}
int change_spa1(char *str , char *str1)
{
	char *temp = str1;
	int count = 0;
	while(*str != '\0') {
		while(*str1 != '\0') {
			if (*str == *str1) {
				return count;
				} 
				str1++;
			}
			str1 = temp;
			str++;
			count++;
		}
	return count;
}
