#include<stdio.h>
#include<string.h>

void compareString(char string1[20], char string2[20])
{
	if (strcmp(string1, string2) == 0) {
		printf("Both strings are same\n");
	} else {
		printf("No they are different\n");
	}
}

int main()
{
	char string1[20];
	char string2[20];
	scanf("%s", string1);
	scanf("%s", string2);
	compareString(string1, string2);
	return 0; 
}
