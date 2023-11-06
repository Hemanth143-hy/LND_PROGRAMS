#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
int myStrCmp(char *str1, char *str2);
int main ()
{
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
        if(NULL == str1) {
    printf("error fgets is NULL-\n");
    }

	int compare = myStrCmp(str1, str2);
    if (compare == 0) {
		printf("%d\n " , compare);
    } else if (compare == 1) {
		printf("%d\n",compare );
	} else if( compare == -1) {
		printf("%d\n", compare);
	}
   	free(str1);
    free(str2);
    str1 = str2 = NULL;
    return 0;
}
int myStrCmp(char *str1, char *str2)
{
	while (*str1 != '\0' &&  *str2 != '\0') {
        if(*str1 == *str2) {
			str1++;
            str2++;
        } else if (*str1 > *str2) {
          	return 1;
            break;
         } else {
         	return -1;
            break;
         }
    }
        return 0;
}
