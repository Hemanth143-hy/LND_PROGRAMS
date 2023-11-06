#include <stdio.h>
int main()
{
	int row;
	int column;
	for (row = 1; row <= 5; row++) {  
		for (column = 1; column <= 5;column++) {
			printf("%c", 64 + column);
		}
	printf("\n");
	} 
	return 0;
}
	

 	
