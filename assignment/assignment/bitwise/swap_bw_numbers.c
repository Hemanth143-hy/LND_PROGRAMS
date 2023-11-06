#include<stdio.h>
int swap_bit(unsigned int , unsigned int , unsigned int , unsigned int);
int binary(unsigned int snum);
int binary1(unsigned int dnum);
int main() {
        unsigned int snum ;
        unsigned int dnum ;
        unsigned int s ;
		unsigned int d ;
        printf("Enter the source number:");
        scanf("%d",&snum);
        printf("Enter the src position to swap:");
        scanf("%d",&s);
        printf("Enter the destination number :");
        scanf("%d",&dnum);
		printf("Enter the des position to swap:");
		scanf("%d",&d);
        binary(snum);
		binary1(dnum);
        swap_bit(snum , dnum , s , d);
        return 0;
}
int binary(unsigned int snum)
{
        int i ;
        for(i = 0; i < 8; i++) {
                if(snum & 128) {
                        printf("1");
                } else {
                        printf("0");
                }
        snum <<= 1;
        }
        printf("\n");
}
int binary1(unsigned int dnum)
{
        int i ;
        for(i = 0; i < 8; i++) {
                if(dnum & 128) {
                        printf("1");
                } else {
                        printf("0");
                }
        dnum <<= 1;
        }
        printf("\n");
}
int swap_bit(unsigned int snum , unsigned int dnum, unsigned int s, unsigned int d )
{
        if ((snum & ((1<< s) >> s)) && (dnum & (1 << d))) {
                printf("The swapping is not required");
        } else {
                snum ^= (1 << s );
				dnum ^= (1 << d );
                printf("the decimal numbers after swapping is :%d %d\n",snum , dnum);
                binary(snum);
				binary1(dnum);
        }
}
