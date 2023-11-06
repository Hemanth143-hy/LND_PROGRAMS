#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20 
int mystrspan(char *str1, char *str2);
int main()
{       int count = 0;
        char *str1 = NULL;
        str1 = (char*) malloc(SIZE * sizeof(char));
        char *str2 = NULL;
        str2 = (char*) malloc(SIZE * sizeof(char));
        if(NULL == str1  || NULL == str2) {
        	printf("error memory is not allocated-\n");
        	exit(0);
        	}
        printf("enter the string in str1-");
        fgets(str1, SIZE, stdin);
        *(str1 + (strlen(str1) - 1)) = '\0';
        if(NULL == str1) {
        	printf("error fgets is NULL-\n");
        	}
        printf("enter the string in str2-");
        fgets(str2, SIZE, stdin);
        *(str2 + (strlen(str2) - 1)) = '\0';
        if(NULL == str2) {
        	printf("error fgets is NULL-\n");
		}
       // mystrspan(str1, str2);
		printf("the count is %d",mystrspan(str1,str2));
//        printf("Len : %d\n", spn);
        return 0;
}
int mystrspan(char *str1, char *str2)
{
	int count=0;
	char *temp = str2;
	while(*str1 != '\0') {
		while(*str2 != '\0') {
			if(*str1 == *str2) {
				count = count+1;
				str2 = temp;
				break;
			} else {
				str2++;
			}
	
		}
		str1++;
	}
	return count;
}
