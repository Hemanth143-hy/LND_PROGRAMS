#include<stdio.h>	
#include<string.h>
#include<stdlib.h>
#define SIZE 50
int* mycpm(char *str1 , char *str2);
int main()
{
	char* str1 = NULL;
	char* str2 = NULL;
	char num;
	str1 = (char*) malloc( SIZE * sizeof(char));
	str2 = (char*) malloc( SIZE * sizeof(char));
	printf("Enter the string1 :");
	fgets(str1 , SIZE , stdin);
	*(str1 + (strlen(str1)-1)) = '\0';
	printf("Enter the string2:");
	fgets(str2 , SIZE , stdin);
	*(str2 + (strlen(str1)-1)) = '\0';
	int compare = mycpm(str1,str2);
	if(compare == 0)
			printf("strings are equal ");
	if (compare == 1)
			printf("string1 is greater");
	else 	
			printf("less than ");
	free(str1);
	free(str2);
	str1 = NULL ;
	str2 = NULL ;
}
int* mycpm(char *str1 , char *str2)
{	
	int flag = 0;
	while(*str1 != '\0' && *str2 != '\0') {
		  if(*str1 != *str2) {
					flag = 1;
			}
			str1++;
			str2++;
	}
	if (flag == 0)
		return 0;
	if(flag == 1)
		return 1;
	else 
		return -1;
}
