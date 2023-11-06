#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *sptr;
	FILE *dptr;
    char str;
    sptr = fopen("first11.txt","a+");
	dptr = fopen("destnation.txt","a+");
    if(sptr == NULL || dptr == NULL) {
		printf("error");
    	exit(1);
    } else {
		while ((str = fgetc(sptr)) != EOF) {
			fputc(str, dptr);
		}
		printf("successfully copied");
	 	fclose(sptr);
		fclose(dptr);
		}
	return 0;
}
