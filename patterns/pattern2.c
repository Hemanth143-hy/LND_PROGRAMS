#include<stdio.h>
int main()
{
	int row;
	int column;
	for(row = 1; row <= 5; row++) {
		for(column = 5; column >= row ; column--) {
			printf(" * ");
		}
	printf(" \n ");
	}
	return 0;
}

