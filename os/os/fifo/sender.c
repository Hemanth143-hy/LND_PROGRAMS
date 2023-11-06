#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define SIZE 50
int main()
{
	FILE *ptr;
	int res;
	char buf[SIZE] = {0};
	ptr = fopen("sender.txt", "r");
	if (ptr == NULL) {
		printf("Faild to open file");
	}
	fread(buf, SIZE ,1,ptr);
	res = open("fifo1",O_WRONLY);
	write(res,buf,strlen(buf));
	fclose(ptr);
}
