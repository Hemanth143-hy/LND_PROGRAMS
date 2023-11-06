#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50
int strPalindrome(char *str);
int main()
{
        char* str = NULL;
        str = (char*) malloc(SIZE * sizeof(char));
        printf("Enter the string:");
        fgets(str , SIZE , stdin);
		if(strPalindrome(str))
			printf("The string is not palindrome");
		else 
			printf("The string is  palindrome");
		free(str);
		str =NULL;
}
int strPalindrome(char *str)
{
        int i;
        int c = 0;
        int n;
        n = strlen(str);
        for (i = 0; i < n/2; i++)       {
                if(str[i] == str[n-1-i])
                c++;
        }
        if ( c == i)
			return 0;
        else
        	return 1;
}
