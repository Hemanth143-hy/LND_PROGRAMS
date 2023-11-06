#include<stdio.h>
#if 1
int binary(int);
int swap(int);
int main()
{
	int i;
	int num = 0xABCD;
//	printf("enter the number:");
//	scanf("%" ,&num);
	binary(num);
	swap(num);
//	printf("%d",strlen(num));
	return 0;
}
int binary(int num)
{
	int i;
	int count=0;
	for(i = 0 ; i < 16 ; i++) {
		if(num & 0x8000) {
			printf("1");
			count++;
		} else {
			printf("0");
		}	 
	num <<= 1 ;
	}
	printf(" count for set bit :%d\n",count);
}
int swap(int num) {
	num = (num << 12) | (num >> 12) |(num & 0x0ff0) ;
	binary(num);
}
#endif
#if 0
int main()
{
 	int num = 15;
	int n = 5;
	int res;
	res = num ||(1);
	printf("%d", res);
}
#endif

