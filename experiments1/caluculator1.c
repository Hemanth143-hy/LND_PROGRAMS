#include<stdio.h>
int main( )
{
	int number1;
	int number2;
	char op;
	int count = 0;
	printf("enter the number1 :"); 
		scanf("%d",&number1);
	if(number1 >= 'a'&& number1 <= 'z' || number1 >= 'A'&& number2 <= 'Z') {
			count = count + 1;
			printf("invalid");
	}  
	printf("enter the number2 :"); 
		scanf("%d",&number2);
	if(number2 == 'a'&& number2 <= 'z'|| number2 >= 'A'&& number2 <= 'Z') {
			count = count + 1;
			printf("invalid");
	}  
	printf("Enter character:  + - / *");
		scanf(" %c",&op);
		switch(op) 
		{
			case '+':
				printf("\n addition :%d \n",number1+number2);
			break;
			case '-':
				printf("\n subtraction :%d \n",number1-number2);
			break;
			case '/':
				printf("\n division :%d \n",number1*number2);
			break;
			case '*':
				if(number2 == 0) {
					printf("the number2 is 0");
				} else {
				printf("\n multipilcation :%d\n" , number1/number2);
			}
			default:
				printf(" \n invalid input");
		}
	return 0;

}
