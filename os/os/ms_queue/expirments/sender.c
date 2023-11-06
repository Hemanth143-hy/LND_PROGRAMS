#include "header.h"

void fileread(FILE *, char[], char[], char[]);

int main ()
{
	mqd_t sdfd;
	struct mq_attr att;
	att.mq_flags = 0;
	att.mq_maxmsg = 10;
	att.mq_msgsize = MAX;
	att.mq_curmsgs = 0;
	char buff1[MAX] = {0};
	char buff2[MAX] = {0};
	char buff3[MAX] = {0};
	FILE *fp ;
	int res;
	
	sdfd = mq_open("/mymq", O_CREAT | O_RDWR, 0660, &att);
	if(sdfd == -1) {
		printf("error 1\n");
		exit(0);
	}
	fp = fopen("input.txt", "r");
	if(fp == NULL) {
		printf("error 2\n");
		exit(0);
	}
	fileread(fp, buff1, buff2, buff3);
	res = mq_send(sdfd, buff1, strlen(buff1), 3);
	if(res == -1) {
		printf("error 3\n");
		exit(0);
	}
	res = mq_send(sdfd, buff2, strlen(buff2), 2);
	if(res == -1) {
		printf("error 3\n");
		exit(0);
	}
	res = mq_send(sdfd, buff3, strlen(buff3), 1);
	if(res == -1) {
		printf("error 3\n");
		exit(0);
	}
	fclose(fp);
	mq_close(sdfd);
	return 0;
}
void fileread(FILE *fptr, char b1[], char b2[], char b3[])
{
	int count;
	char ch;
	fseek(fptr, 0 , SEEK_END);
	count = ftell(fptr);
	printf("%d", count);
	fseek (fptr, 0 , SEEK_SET);
	count = count/3;
	int i = 0;
	int j = 0;
	int k = 0;
	while((ch = fgetc(fptr)) != EOF) {
		if (i < count) {
			b1[i] = ch;
		} else if (i >= count && i < (count *2)) {
			b2[j] = ch;
			j++;
		} else {
			b3[k] = ch;
			k++;
		}
		i++;
	}
}
