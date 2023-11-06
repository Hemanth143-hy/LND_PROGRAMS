#include <stdio.h>
#define SET(NUM,P) (NUM |=  (1<<P))
#define CLR(NUM,P) (NUM |= ~(1<<P))
int main()
{
        unsigned char num;
        unsigned char p;
       	printf("number:");
        scanf("%hhd", &num);
        printf("position");
        scanf("%hhd", &p);
        SET(num, p);
        printf("number %d\n", num);
        CLR(num, p);
        printf("position %d\n", num);
}
