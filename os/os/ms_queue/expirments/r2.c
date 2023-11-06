#include "header.h"

int main ()
{
	mqd_t rdfd;
	char buff[MAX] = {0};
	FILE *fp ;
	rdfd  = mq_open("/mymq", O_RDONLY, 0660, NULL);
	if(rdfd == -1) {
		printf("error 1\n");
		exit(0);
	}
	fp = fopen("output.txt", "a+");
	if(fp == NULL) {
		printf("error 2\n");
		exit(0);
    }
	int res = mq_receive(rdfd, buff, MAX, 0);
	printf("%d" , res);
    if(res == -1) {
		printf("error 3\n");
		exit(0);
	}
	fwrite(buff, strlen(buff), 1, fp);
//	printf("%s\n" , buff);
	fclose(fp);
	mq_close(rdfd);
    return 0;
}
