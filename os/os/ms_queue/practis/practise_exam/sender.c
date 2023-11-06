#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>

#define SIZE 256
int main() {
	mqd_t mq_server;
	struct mq_attr attr;
		attr.mq_flags = 0;	
		attr.mq_maxmsg = 10;
		attr.mq_msgsize = SIZE;
		attr.mq_curmsgs = 0;
	if((mq_server = mq_open("/server" , O_WRONLY | O_CREAT , 0660 , &attr)) == -1) {	
		printf("error in opening the mq_open");
		exit(1);
	}
	char buff[SIZE];
	printf("enter the msg to the client");
	fgets(buff , SIZE , stdin);
	if((mq_send(mq_server , buff , strlen(buff)+1 , 0)) == -1) {
		printf("error in sending");
	}
	printf("msg sent to client");
}
