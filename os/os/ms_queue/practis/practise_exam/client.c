#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>

#define SIZE 256
int main() {
	mqd_t mq_client;
/*
	struct mq_attr attr;
		attr.mq_flags = 0;	
		attr.mq_maxmsg = 10;
		attr.mq_msgsize = SIZE;
		attr.mq_curmsgs = 0;*/
	if((mq_client = mq_open("/server" , O_RDONLY  , 0660 , NULL)) == -1) {	
		printf("error in opening the mq_open");
		exit(1);
	}
	char buff[SIZE];
	if((mq_receive(mq_client , buff , SIZE , NULL)) == -1) {
		printf("error in receive");
	}
	printf("%s", buff);
	if((mq_close(mq_client)) == -1) {	
		printf("error in closing");
	}
	//mq_unlink("/server"); 
//	printf("%s", buff);
	printf("msg received");
	exit(0);

}
