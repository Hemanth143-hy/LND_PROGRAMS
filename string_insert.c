#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
char* sts(char  *str , char ch , int pos);
int main()
{
	char *str = NULL ;
	str = ((char*) malloc (SIZE  * (sizeof (char))));
	printf("Enter the first string:");
	fgets(str , SIZE , stdin);
		*(str + (strlen(str)-1)) = '\0';
	char ch;
	printf("enter the character to repalce:");
	scanf("%c", &ch);
	int pos ;
	printf("enter the position to insert:");
	scanf("%d", &pos);
	printf("%s",sts(str , ch , pos));
	return 0;
}
char* sts(char *str , char ch , int pos)
{ 
	char len ;
	char i; 
	len =(strlen(str));
	for(i = len; i > 0 ; i--) {
		*(str + i + 1) = *(str + i);	
		if(i == pos) {
			*(str + i) = ch;
		break;
		}
	}
	return str;
}


