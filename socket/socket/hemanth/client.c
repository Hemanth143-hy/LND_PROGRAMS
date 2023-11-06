#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#define SIZE 20
int main () {
        int cfd = 0;
        int bin = 0;
        int con =0;
        char buff[SIZE];
        struct sockaddr_in client; //for client
                client.sin_family = AF_LOCAL;                   //domain name
                client.sin_port = htons(1234);                  //port is given by user
                client.sin_addr.s_addr = INADDR_ANY;    // predefined structure
                client.sin_zero[8] ='\0';                       //it is for padding
        //creating the socket
        cfd = socket(AF_LOCAL , SOCK_STREAM , 0);
        if(cfd == -1) {
                printf("socket is not created");
                exit(1);
        }
        con =connect(cfd , (struct sockaddr*)&client , sizeof(client));
        if(con == -1) {
                printf("connect is not done");
                exit(1);
        }
        printf("Enter the message for server :\n");
        fgets(buff, SIZE, stdin);
        write(cfd , buff, SIZE);
        read(cfd , buff, SIZE);
        printf("The message from Server: %s\n" , buff);
        close(cfd);
        return 0;
}

