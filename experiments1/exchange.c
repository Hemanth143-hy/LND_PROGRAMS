#include<stdio.h>
#include<stdlib.h>
#if QUES == 1
int main()
{
	char ch[20];
	printf("enter the string data:");
	fgets(ch ,20 ,stdin);
//	printf("%c%c",ch[0],ch[1]);
	ch[1] = '$';
	printf("%s",ch);
}	
#endif
#if QUES == 2
int main()
{
	char A[10];
	printf("Enter the string data:");
	fgets(A , 10 ,stdin);
	A[1] = '@';
	A[2] = '$';
	printf("%s",A);
}
#endif
#if QUES == 3
int main()
{	
	
	char *ptr;
	ptr = (char*) malloc(20);
	printf("Enter the string data:");
	fgets(ptr ,10 , stdin);
	ptr [0]  ='1';
	printf("%s",ptr);
} 
#endif
#if QUES == 4
int main()
{
	char ch[20];
	printf("Enter the string data:");
	fgets(ch , 20 ,stdin);
	for(int i = 0; i < 4; i++) {
		ch[i] = ' ';
	printf("%s",ch);
	}
}
#endif
 
