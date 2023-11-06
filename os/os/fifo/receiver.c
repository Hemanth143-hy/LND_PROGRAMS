#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define SIZE 50
int main()
{
	int res;
	int n;
	FILE *ptr;
	char buf[SIZE] = {0};
	res = open("fifo1" , O_RDONLY);	
	n = read( res , buf ,  SIZE);
	ptr = fopen("receiver.txt" ,"w");
	if(ptr == NULL) {	
		printf("failed to open");
	}
	fwrite(buf, n-1 , 1, ptr);
	fclose(ptr); 
}
