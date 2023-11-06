#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 15
void str_ins( char *str ,char ch  , int pos);

int main() {
	char *str;
	char ch;
	int pos;
	str = (char*)malloc(SIZE * sizeof(char));
	printf("enter the string:");
	fgets(str , SIZE , stdin);
	printf("enter the character to insert:");
	scanf("%c", &ch);
	printf("enter the position to insert:");
	scanf("%d",&pos);
	str_ins(str , ch , pos);
	printf("the string after insertion :%s", str);
	return 0;
}
	
void str_ins(char* str , char ch , int pos) {
	int len = strlen(str);
	int i = len-1;
	while(*(str + i)) {
		*(str + len) = *(str +len - 1);
			if( i == pos) {
				*(str + i) = ch;
				break;
			}
		i--;
		len--;
	}
}	
