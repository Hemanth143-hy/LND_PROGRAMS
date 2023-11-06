#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50

char *mycat(char *dest , char *src);
int main()
{
        char* src = NULL ;
        char* dest = NULL  ;
		src = (char*)malloc (SIZE * sizeof(char));
		dest = (char*)malloc (SIZE * sizeof(char));
        printf("Enter the source:");
        fgets(src , SIZE , stdin);
        printf("Enter the destination:");
        *(src + (strlen(src)-1))='\0';
        fgets(dest , SIZE , stdin);
//      mycat(dest,src);
        *(dest + (strlen(dest)-1))='\0';
        printf("The string after cat:%s\n",(mycat(dest,src)));
		free(src);
		free(dest);
		src = NULL;
		dest = NULL;
}
char *mycat(char *dest , char *src)
{       char *temp;
        temp = dest;
        while(*temp != '\0') {
                temp++;
        }
        while(*src !='\0') {
                *temp = *src;
                temp++;
                src++;
        if(temp > src)
                *temp = '\0';
        }
        return dest;
}
