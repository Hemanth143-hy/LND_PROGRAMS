#include <stdio.h>
//#define test(num) ((num << 24) | (num >> 24) | (((num << 8) >> 24) <<8) | (((num >> 8) << 24) >> 8) )

int main() { 
	int i =0;
	unsigned int num1 = 0x6789;
	num1 = ((num1 << 24) | (num1 >> 24) | (((num1 << 8) >> 24) <<8) | (((num1 >> 8) << 24) >> 8) );
	printf("%d\n",num1);
/*
	for( i = 0; i <32 ; i++) {
		if(res & 0x80000000) {
			printf("1");
		} else {
			printf("0");
		}
		num1 = num1 << 1;
	}*/
}
