#include<stdio.h>
int checkpowerofTwo(int n);
int checkpowerofTwo(int x)
{
	if(x == 0)
		return 0;
	while (x != 1) {
		if( x % 2 != 0)
		return 0;
	x /=2;
	}
	return 1;
}
int main()
{
	int num;
	printf("Enter the num you want to check : \n");
	scanf("%d", &num);
	if (checkpowerofTwo(num) == 1){
		printf("%d is power of 2\n", num);
	} else {
	printf("%d is not power of 2\n", num);
	}
	return 0;
}
