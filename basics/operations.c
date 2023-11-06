#include<stdio.h>
#if  QUES == 1
int main()
{
	unsigned char ch1 = 63;
	unsigned char ch2 = 28;
	unsigned char ch3 = 36;
	unsigned char  res = (ch1 & ch2) | ch3;
	unsigned char res1 = (ch2 & ch3) | ch1;
	printf("%d",res);
	printf("%d",res1);
}
#endif
#if QUES == 2
int main()
{
	unsigned char ch1 = 63;
	unsigned char ch2 = 28;
	unsigned char res = ch1 & ch2 ;
	unsigned char res1= ch1 | ch2 ;
	printf(" and operation:%d\n",res);
	printf("or operation: %d",res1);
}
#endif
#if QUES == 3
int main()
{
	unsigned short int ch1 = 512;
	unsigned short int ch2 = 768;
	unsigned short int res = ch1 & ch2 ;
	unsigned short int res1 = ch1 | ch2 ;
	printf(" and operation :%u\n",res);
	printf(" or operation : %u\n",res1);
}
#endif
#if QUES == 4
int main()
{
	unsigned char ch1 = 63;
	unsigned char ch2 = 28;
	unsigned char res = ch1 << 4;
	unsigned char res1 = ch2 >>2;
	printf("%d\n",res);
	printf("%d",res1);
}
#endif
#if QUES == 5
int main()
{
	unsigned char ch1 = 63;
	unsigned char ch2 = 28;
	unsigned char res = (ch1 & ch2) & (ch1 | ch2);
	printf("%d",res);
}
#endif
 
