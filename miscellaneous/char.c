#include<stdio.h>
#if 0
int main()
{
	signed int num = -1;
	if(num >= 1)
	printf("hai");
	else 
	printf("hello");
	return 0;
}
int main()
{
	unsigned int num = 1 ;       /*the number is compared with unsigned int with  -1  is shows is negative value is greater ,
					    because it takes the 2's complement of the value and then compared so it prints hello in output which is else part */
	if(num >= -1)
	printf("hai");
	else 
	printf("hello");
	return 0;
}
#endif
#if 1
int main()
{
	float num = 1.2;
	if(num == 1.2)
	printf("haiii");
	else 
	printf("hello");
	return 0;
}
#endif
