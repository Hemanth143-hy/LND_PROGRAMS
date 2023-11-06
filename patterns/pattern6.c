#include <stdio.h>
int patterns(int rows,int col)
{
	for(rows = 1; rows <= 5; rows++) {  
		for(col = 1;col <= rows; col++)
		{	
			printf(" * ");
		}
	printf("\n");
	}
}
int main()
{
	int rows;
	int col;
	patterns(rows,col);
	return 0;
}

