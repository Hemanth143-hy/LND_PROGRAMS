#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int test;
	char k;
	char str[10];
	int *p;
	short sh;
} things;
int main(int argc , char *argv[]) {
	int i;
	things = {12 , 'k' ,"testing"	 , &i , 256 };
	printf(" llu\n" , sizeof(t));
	unsigned char data;
	for(i = 0; i < sizeof(things); i++) {
		if(i % 8 ==0) {
			printf("\n");
		}
		data = *(((unsigned char*)&things) +i);
		printf("%02x",data);
	}
	return 0;
}
	
