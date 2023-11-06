#include<stdio.h>
int main( )
{	
	char arr[32][12]={"int","float","long","unsigned","while","for","register","extern","static","double","break","return","if","void","goto","union","auto","enum","short","case",
							"signed","continue","do","switch","else","char","const","type def","size of","volatile","default","struct"};
	for(int i = 1 ; i < 32 ; i++){
		printf("%s \n",arr[i]);
	}	
	return 0;
}

