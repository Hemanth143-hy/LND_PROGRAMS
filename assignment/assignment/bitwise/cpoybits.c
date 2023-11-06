#include<stdio.h>
int copying(unsigned int , unsigned int , unsigned int , unsigned int , unsigned int); 
int swap(unsigned int );
int main()
{   
	unsigned int snum ;
	unsigned int dnum ;
	unsigned int num;
	unsigned int src;
	unsigned int des;
	printf("Enter the source number:");
	scanf("%d",&snum);
	printf("Enter the destination number:");
	scanf("%d" ,&dnum);
	printf("Enter the number of bits to be copied:");
	scanf("%d",&num);
	printf("Enter the src to start copy:");
	scanf("%d",&src);
	printf("Enter the des to copy:");
	scanf("%d",&des);
	copying(snum , dnum , num , src , des);
	return 0;
}
int copying(unsigned int snum , unsigned int dnum , unsigned int num , unsigned int src , unsigned int des)
{
	if(	src < 0 || des > 31) {
		return 0 ;
	}
	swap(dnum);
	swap(snum);
	int nlength = ((num)<<(src-1)) & dnum;
	snum = snum | nlength;
	printf("%d\n", snum);
	swap(num);
	swap(dnum);
	swap(snum);
}
int swap(unsigned int num)
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

	
