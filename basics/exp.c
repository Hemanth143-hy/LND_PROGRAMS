#include<stdio.h>
void display();
void fun();
int main() {
//    static	int a;
	display();
	//display();
	//display();
	fun();
//	printf("%d", a);
}
int c;
void display() {
  	static int a = 5;
	printf("c : %d\n", c);
 //	c = a+5;
//	c++;
//	printf("%d",c);
}

void fun()
{
	int d;
	printf("%d\n", d);
	printf("%d\n", c);
}
