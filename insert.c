#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
//ichar sts(char  *str , char ch , int pos);
int main()
{
		char temp;
		int i;
        char str = NULL;
        str = ((char) malloc (SIZE  * (sizeof (char))));
        printf("Enter the first string:");
        fgets(str , SIZE , stdin);
        (*(str + (strlen(str)-1))) = '\0';
        char ch;
        printf("enter the character to insert:");
        scanf("%c", &ch);
        int pos ;
        printf("enter the position to insert:");
        scanf("%d", &pos);
		int len = strlen(str);
        for(i = len; i > 0 ; i--) {
        ((str + i) + 1) = (str + i);
         if( i == pos) {
				temp = (str + i);
                (str + i) = ch;
				((str + i) + 1) = temp;
                continue;
        }
}
                printf("%s", (str));
}


