#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>

int main() {
	mqd_t mq_server;	
	mq_server = mq_open("/server" , O_RDONLY , 0660 , NULL);
	mq_close(mq_server);
	mq_unlink("/server");
	return 0;
}
