#include<stdio.h>
int main()
{
	FILE *fptr;
	int value;
	fptr = fopen("num.txt","rwb");
	for(value = 1; value <= 30; value++) {
		printf("%d\t",value);
		putw(value,fptr);
	}
	fclose(fptr);
}

