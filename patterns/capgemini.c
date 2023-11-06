#include<stdio.h>
int capgeminipattern(int row , int col)
{
	for(row = 1; row <= 4; row++) {
		for(col = 1; col <= 5; col++)
		{
		if( row == 3 & col == 1 || row == 2 & col == 2 || row == 1 & col == 3 || row == 2 & col == 3 || row == 2 & col == 4 || row == 3 & col == 5)
		printf(".");
		else 
		printf(" ");
		}
	printf("\n");
	}
}
int main()
{
	int row;
	int col;
	capgeminipattern(row , col);
	return 0;
}

