#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>       
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h> 
#define SIZE 20
int main () {
	int sfd = 0;
	int bin = 0;
	int cfd = 0;
	char buff[SIZE];
	struct sockaddr_in server; //for server
	struct sockaddr_in client; //for client
		server.sin_family = AF_LOCAL; 			//domain name 
		server.sin_port = htons(1234); 			//port is given by user
		server.sin_addr.s_addr = INADDR_ANY; 	// predefined structure
		server.sin_zero[8] ='\0';      			//it is for padding
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
		read(cfd , buff , SIZE);
		printf(" The message from client: %s\n" , buff);
		printf("Enter the message for client :\n");
		fgets(buff, SIZE, stdin);
		write(cfd , buff, SIZE);
		close(cfd);
	
	}
	close(sfd);
	return 0;.
}
