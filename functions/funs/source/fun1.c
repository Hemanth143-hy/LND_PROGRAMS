#include "header.h"
extern int a;
static int d = 40;
void fun1()
{
	printf("%d \n ",a-d);
}
void fun2()
{
	printf("%d \n " ,a+d);
} 

