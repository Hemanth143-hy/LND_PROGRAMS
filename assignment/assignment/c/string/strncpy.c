#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50
char *mstrcpy(char *dest , char *src ,int n);
int main()
{
		int n;
        char* src = NULL;
        src = (char*) malloc(SIZE * sizeof(char));
        char* dest = NULL;
        dest = (char*) malloc(SIZE * sizeof(char));
        printf("Enter the string:");
        fgets(src , SIZE , stdin);
		printf("enter the number of elements to be copied:");
		scanf("%d",&n);
	//	mstrcpy(dest , src , n);
        printf("The string is:%s", mstrcpy(dest , src , n));
}
char *mstrcpy(char *dest ,char *src , int n)
{
        char* temp;
        temp = dest;
		int i;
        for(i = 0 ; i < n && src[i] != '\0'; i++) {
			 	*temp++ = *src++;
		}
		dest[n] = '\0';
        return dest;
}

