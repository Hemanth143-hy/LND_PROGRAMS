#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define SERVER_QUEUE_NAME "/example-server"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

int main ()
{
	FILE *ptr;
    int i =0;
    char ch;
    int count = 0;
	int j = 0;
	int k = 0;
	char buf1[MSG_BUFFER_SIZE];
	char buf2[MSG_BUFFER_SIZE];
	char buf3[MSG_BUFFER_SIZE];
    mqd_t qd_ser; // queue descriptors
	mqd_t qd_ser1;
	mqd_t qd_ser2;
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;
    ptr = fopen("input.txt" , "r");
    if ((qd_ser = mq_open (SERVER_QUEUE_NAME, O_WRONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("Server: mq_open (server)");
        exit (1);
    }

    char in_buffer [MSG_BUFFER_SIZE];
    while((ch = fgetc(ptr)) != EOF) {
		//in_buffer[i] = ch;
		count++;
    }
	printf("%d\n", count);
	fseek(ptr, 0, SEEK_SET);
    count = count/3;
    printf("%d" , count);
	while((ch = fgetc(ptr)) != EOF) {
		if(i < count) {
			buf1[i] = ch;
		} else if((i > count) && (i < count)) {
			buf2[j] = ch;
			j++;
		} else {
			buf3[k] = ch;
			k++;
		}
		i++;
	}
    fgets(buf1, MAX_MSG_SIZE, ptr);
//      fprintf( ptr , "%s" , in_buffer);
    if (mq_send (qd_ser,buf1, strlen (buf1) + 1, 0) == -1) {
        perror ("Server: Not able to send message to client1");
    }
	if (mq_send (qd_ser1 , buf2 , strlen(buf2)+1 ,0) == -1) {	
		perror ("Server : Not able to send messge to client2");
	} 
    printf ("Server: response sent to client.\n");
}
