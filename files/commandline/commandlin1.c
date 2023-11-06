#include<stdio.h>
int main ( int argc , char *argv[]) {
	if(argc == 2) {
		printf("the given arguments are %s-\n",argv[1]);
	} else if (argc < 2) {
		printf("there is only one arguments \n");
	} else {
		printf("There is more than one  arguments given \n");
	}
} 
