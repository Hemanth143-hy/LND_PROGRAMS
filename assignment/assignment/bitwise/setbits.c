#include<stdio.h>
int binary(unsigned int num);
int binary1(unsigned int num);
int main()
{
	unsigned int num;
	printf("Enter the number:");
	scanf("%d",&num);
	binary(num);
	binary1(num);
}
int binary(unsigned int num)
{
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
int binary1(unsigned int num)
{
	int i ;
	int count = 0;
	for(i = 0; i < 8; i++) {
		if(num & 128) {
			printf("1");
		//	count = count +1;
		} else {
			printf("0");
			count = count +1;
		}
	num <<= 1;
	}
	printf("\n");
	printf("the count of clear bits :%d\n",count);
}
