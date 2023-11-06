#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50
char *mstrcpy(char *src);
int main()
{
	char* src = NULL;
    src = (char*) malloc(SIZE * sizeof(char));
    printf("Enter the string:\n");
    fgets(src , SIZE , stdin);
	*(src+(strlen(src)-1))='\0';
	mstrcpy(src);
    printf("The string is:\n%s\n",src);
	free(src);
	src = NULL;
}
char *mstrcpy(char *str)
{
	int len2 = strlen(str);
	char *len = str + strlen(str);
	printf("%d\n", len2);
	len--;
	char temp;
	while(len > str) {
		temp = *len;
		*len = *str;
		*str = temp;
		len--;
		str++;
	}
	return str;

}
