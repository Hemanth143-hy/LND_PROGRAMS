#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#define SIZE 20
int main () {
        int sfd = 0;
        int bin = 0;
        int cfd = 0;
        pid_t pid;
        char buff[SIZE];
		 str2ba("SERVER_BLUETOOTH_ADDRESS", &server_address.rc_bdaddr);
    server_address.rc_channel = (uint8_t) 1;  // Use channel 1
        sfd = socket(AF_LOCAL , SOCK_STREAM , 0);
        if(sfd == -1) {
                printf("socket is not created");
                exit(1);
        }
        //bind
        bin = bind(sfd,(struct sockaddr*)&server , sizeof(server));
        if(bin == -1) {
                printf("bind is not done");
                exit(1);
        }
        //listen
                bin = listen(sfd , 5);
                if(bin == -1) {
                        printf("error in listening");

                }
        for( ; ; ) {
                bzero(buff, SIZE);
                int len = sizeof(client);
                cfd = accept(sfd , (struct sockaddr*)&client , &len);
                if(cfd == -1) {
                        printf("the accepted is not performed");
                }
                if((pid = fork()) == 0) {
                        read(cfd , buff , SIZE);
                        printf(" The message from client: %s\n" , buff);
                        printf("Enter the message for client :\n");
                        fgets(buff, SIZE, stdin);
                        write(cfd , buff, SIZE);
                        close(cfd);
                }
        }
        close(sfd);
        return 0;
}

