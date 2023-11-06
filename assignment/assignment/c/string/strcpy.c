#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50
char *mstrcpy(char *dest , char *src);
int main()
{
        char* src = NULL;
		src = (char*) malloc(SIZE * sizeof(char));
        char* dest = NULL;
		dest = (char*) malloc(SIZE * sizeof(char));
        printf("Enter the string:");
        fgets(src , SIZE , stdin);
        printf("The string in destination:%s",mstrcpy(src, dest));
}
char *mstrcpy(char *dest ,char *src)
{
        char* temp;
        temp = dest;
        while(*src != '\0') {
			   *temp++ = *src++;
        }
        return dest;

}

