#include<stdio.h>
int swap_bit(unsigned int , unsigned int , unsigned int);
int binary(unsigned int num);
int main() {
	unsigned int num ;
	unsigned int src ;
	unsigned int des ;
	printf("Enter the number:");
	scanf("%d",&num);
	printf("Enter the src position to swap:");
	scanf("%d",&src);
	printf("Enter the des position to swap:");
	scanf("%d",&des);
	binary(num);
	swap_bit(num , src , des);
	return 0;
}
int binary(unsigned int num)
{
	int i ;
	for(i = 0; i < 8; i++) {
		if(num & 128) {
			printf("1");
		} else {
			printf("0");
		}
	num <<= 1;
	}
	printf("\n");
}
int swap_bit(unsigned int num , unsigned int src , unsigned  int des)
{
	if (((num & (1 << src))>>src) == (((num & (1 << des))>>des)))  {
		printf("The swapping is not required");
	} else {
		num ^= ((1 << src )|(1 << des));
		printf("the decimal numbers after swapping is :%d\n",num);
		binary(num);
	}
}

