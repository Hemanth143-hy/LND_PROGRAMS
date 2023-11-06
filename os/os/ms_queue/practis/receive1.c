#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define CLIENT_QUEUE_NAME "/example-server"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

int main ()
{
	char client_queue_name[64] = {0};
    mqd_t qd_client;
    if ((qd_client = mq_open(CLIENT_QUEUE_NAME, O_RDONLY, QUEUE_PERMISSIONS, NULL)) == -1) {
    	perror ("Client: mq_open (client)");
        exit (1);
    }
    if (mq_receive (qd_client, client_queue_name, MSG_BUFFER_SIZE, NULL) == -1) {
    	perror ("Client: mq_receive");
        exit (1);
    }
	FILE *pttr;
    pttr = fopen("outq.txt" , "w");
    fwrite(client_queue_name , strlen(client_queue_name) , 1 , pttr);
    if (mq_close (qd_client) == -1) {
    	perror ("Client: mq_close");
        exit (1);
    }
    printf("%s\n", client_queue_name);
    printf ("Client: yes am \n");
    exit (0);
}
