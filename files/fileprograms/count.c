#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int main()
{
	FILE *fptr;
    int count = 0;
    int ch;
    if ((fptr = fopen("words.txt", "a+")) == NULL) {
   		printf("File does not exit\n");
        	exit(1);
    } else {
    	while ((ch = fgetc(fptr)) != EOF) {
       // 	printf("%c", ch);
            if (ch == ' ' || ch == '\n')
            	count++;
            }
            printf("Number of words : %d\n", count);
           fclose(fptr);
	}
    return 0;
}
