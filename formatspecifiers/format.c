#include<stdio.h>
#if 0 
int main( )
{
	char data = 'A';
	printf(" %c \n", data);
	return 0;
}

}

int main()
{
	int data = 65 ;
	printf("%c\n" , data);
	return 0;
}
int main()
{
	int data =65 ;
    printf("%d\n", data);
    printf("%u\n", data);
    printf("%i\n", data);
    return 0;
}
#endif
#if 0
int main()
{
    int data1;
	int data2;
    int data3;
    printf("Enter value in decimal format:");
    scanf("%d",&data1);
    printf("data1 = %i\n\n", data1);
    printf("Enter value in hexadecimal format:");
    scanf("%i",&data2);
    printf("data2 = %i\n\n", data2);
    printf("Enter value in octal format:");
    scanf("%i",&data3);
    printf("data2 = %i\n\n", data3);
    return 0;
}	
#endif
#if 1
int main()
{
    char blogName[] = "aticleworld";
    printf("%s\n", blogName);
    printf("%24s\n", blogName);
    printf("%-24s\n", blogName);
    printf("%24.6s\n", blogName);
    printf("%-24.6s\n", blogName);
    return 0;
}
#endif

