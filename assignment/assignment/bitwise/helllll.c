#include <stdio.h>
int main() 
{
	int num;
	printf("enter the number:");
	scanf("%d",&num);
	int i ;
	int count = 0;
	for(i = 0; i < 8; i++) {
		if(num & 128) {
			printf("1");
			count = count +1;
		} else {
			printf("0");
		}
	num <<= 1;
	}
	printf("\n");
	printf("the count of set bits :%d\n",count);
}
