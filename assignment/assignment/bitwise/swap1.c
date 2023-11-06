#include<stdio.h>
int main()
{
	int i;
	unsigned int ch =0XAB;
	unsigned int res ;
	printf("%X",(ch>>4|4<<ch));
/*	printf("%d",res);
	for(i = 0; i < 8 ; i++) {
		if(res & 128) {
			printf("1");
		} else { 
			printf("0");
			}
	res >>=1;
		}
	printf("\n");*/
}
