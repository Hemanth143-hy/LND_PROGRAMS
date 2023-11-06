#include<stdio.h>
#include<string.h>
void replace(char str[],int size)
{
	for (int i=0;i<size;i++) {
		if (str[i]=='a')
		{
			str[i]='k';
		}	
	}		
}
int main()
{
	char str[] = "Hemanth am from ap";
	int size = strlen(str);
	replace(str,size);
	printf("%s \n",str);
	return 0;
}

