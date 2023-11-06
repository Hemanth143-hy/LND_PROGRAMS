#include <stdio.h>
int main() 
{
	int row;
	int col;
	int k = 0;
	for(row = 1; row <= 5; row++) {
		for(col = 1; col <= 5 - row ; col++) {
		printf(" ");
	    }
		for(k = 1; k <= (2*row-1); k++)
		{
			printf("*");	
		}
	printf("\n");
	}
	return 0;
}
