#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40
int main ()
{
	char str[SIZE];
	char buff1[SIZE] = {0};
	char buff2[SIZE] = {0};
	char buff3[SIZE] = {0};
	FILE *fp ;
	FILE *fp1 ;
	FILE *fp2 ;
	int count;
	char ch;
	printf("enter the string:");
	fgets(str , SIZE , stdin);
	count = strlen(str);
	printf("%d\n" , count);
	count = count/3;
	printf("%d\n" , count);
	int i = 0;
	int j = 0;
	int k = 0;
	while(str[i] != '\0') {
	if (i < count) {
		buff1[i] = str[ch];
	} else if (i >= count && i < (count *2)) {
		buff2[j] = str[ch];
		j++;
	} else {
		buff3[k] = str[ch];
		k++;
	}
	i++;
	ch++;
	}
	printf("%s\n",buff1);
	printf("%s\n",buff2);
	printf("%s\n",buff3);

	fp = fopen("file1.txt" , "w");
	fprintf(fp ," %s" , buff1);	
	fp1 = fopen("file2.txt" , "w");	
	fprintf(fp1 , "%s" , buff2);	
	fp2 = fopen("file3.txt" , "w");
	fprintf(fp2 , "%s" , buff3);	
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
}
