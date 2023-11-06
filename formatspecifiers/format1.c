#include <stdio.h>
#if 0
int main()
{
    int pos = 14;
    float data = 1.2;
    printf("%*f",pos,data);
    return 0;
}
int main(void)
{
    double data1 = 123456.0;
    printf("%e\n", data1);
    printf("%f\n", data1);
    printf("%g\n", data1);
    printf("\n");
    double data2 = 2345678.0;
    printf("%e\n", data2);
    printf("%f\n", data2);
    printf("%g\n", data2);
    return 0;
}
#define ARRAY_SIZE 10
int main()
{
    char buf[ARRAY_SIZE];
    printf("Enter a string: ");
    fgets(buf,ARRAY_SIZE,stdin);
    printf("string is: %s\n",buf);
    return 0;
}
#endif
#if 1
int main()
{	
	unsigned int num = 192;
	unsigned char ch ;
	ch = num ;
	printf(" %c ",ch);
	return 0;
}
#endif

	
