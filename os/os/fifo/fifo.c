#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
	int res;
	res = mkfifo("fifo1",0777);
	printf("created the fifo:");
}
