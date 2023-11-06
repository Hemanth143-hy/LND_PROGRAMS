#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp = NULL;
	char ch = 'a';
	fp = fopen("abc.txt","w");
	if (fp == NULL)
	{
		printf("error");
		exit(1);
	}
	fputc(ch,fp);	
	fclose(fp);
}

