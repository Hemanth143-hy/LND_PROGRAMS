#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50
char *mystrnappend(char*, const char*, int );
int main ()
{
    int num1;
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
    printf("\nenter the number of char to be append-");
    scanf("%d", &num1);
	mystrnappend(str1, str2, num1);
    printf("string dest - %s\n", str1);
    free(str1);
    free(str2);
    str1 = str2 = NULL;
    return 0;
}
char *mystrnappend(char* str1, const char* str2, int num1)
{
/*    char* temp;
    temp = str1;
    while(*temp) {
        temp++;
    }
    while(*temp = *str2) {
		temp++;
		str2++;
        num--;
        if(num == 0) {
                break;
        }
     }
     return str1;
}*/
	int i = 0;
	
	while(*str1 != '\0') {
		*str1++;
	}  
	while(*str2 != '\0') {
		while(i < num1) {
			*str1 = *str2;
			str1++;
			str2++;	
			i++;
		}
		*str1 == '\0';
		return str1;
	}
}

