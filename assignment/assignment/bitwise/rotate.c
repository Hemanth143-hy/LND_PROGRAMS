#include<stdio.h>
unsigned int left_rotate(unsigned int num , unsigned int n);
unsigned int right_rotate(unsigned int num , unsigned int n);
int binary(unsigned int res);
int binary1(unsigned int res1);
int main()
{
	unsigned int num;	
	unsigned int n;
	printf("Enter the no.:\n");
	scanf("%d",&num);
	printf("Enter the number of bits to shift:\n");
	scanf("%d",&n);
	unsigned int res = left_rotate(num , n);
	unsigned int res1 = right_rotate(num , n);
	printf("After left rotation bits are:\n");
	binary(res);
	printf("After right rotation bits are:\n");
	binary(res1);
	return 0;
}
unsigned int left_rotate(unsigned int num , unsigned int n)
{
	int i;
	for(i = 0; i < n; i++) {
		unsigned int first_bit = num & (1 << 8);
		num = num << 1;
		num = num | ( first_bit >> 0 );
	}
	return num;
}
unsigned int right_rotate(unsigned int num , unsigned int n)
{
	int i;
	for(i = 0; i < n; i++) {
		unsigned int last_bit = num & (1 >> 8);
		num = num >> 1;
		num = num | (last_bit << 8);
	}
	return num;
}
int binary(unsigned int res)
{
	int i ;
	for(i = 0; i < 8; i++) {
		if(res & 128) {
			printf("1");
		} else {
			printf("0");
		}
	res <<= 1;
	}
	printf("\n");
}
int binary1(unsigned int res1)
{
	int i ;
	for(i = 0; i < 8; i++) {
		if(res1 & 128) {
			printf("1");
		} else {
			printf("0");
		}
	res1 <<= 1;
	}
	printf("\n");
}
