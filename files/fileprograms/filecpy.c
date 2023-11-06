#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *ptr;
	int i;
	int count = 0;
	char str[15] = "hello every one";
	ptr = fopen("first.txt","wr");
	if(ptr == NULL) {
		printf("error");
		exit(1);
	} else {
	while ((str , fputc(ptr)) != EOF) {
		if(str == " " || str == EOF) {
			count =  count + 1;
			
	
	fclose(ptr);
	printf("%d", count);
}

	
