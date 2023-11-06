#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define SERVER_QUEUE_NAME "/sp-example-server"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

int main ()
{	
	typedef struct node {
		int b;
		char c;
	}vi;
//	in_buffer = vi; 
//	vi =  in_buffer;  
	mqd_t qd_server; // queue descriptors
	struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;
    if ((qd_server = mq_open (SERVER_QUEUE_NAME, O_WRONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
    	perror ("Server: mq_open (server)");
        exit (1);
	}
    char in_buffer [MSG_BUFFER_SIZE];
//	 vi in_buffer;  
	printf("enter the mesg");
  	fgets(in_buffer,MAX_MSG_SIZE,stdin);	
    if (mq_send (qd_server,in_buffer, strlen (in_buffer) + 1, 0) == -1) {
    	perror ("Server: Not able to send message to client");
    }
    printf ("Server: response sent to client.\n");
}
