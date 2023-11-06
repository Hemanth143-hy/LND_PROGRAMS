#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#define SIZE 30
int main()
{
	char *in;
	in = ((char*) malloc (SIZE * sizeof(char)));
	printf("enter the string");
	fgets(in , SIZE , stdin);
 	int	fd = open("hallio.txt", O_CREAT| O_RDWR , 0600 );
	printf("file descriptor value = %d\n", fd);
  	if(fd == -1) {
     perror("Error: [Failed to Open a file] :" ); 
	 } else {
     printf("File Opened successfully!\n");
	int n = read(fd , in , SIZE);
	write(fd , in , SIZE);
	lseek(fd , 0 , SEEK_SET);
	//printf("pointer is at position %d\n",fd);
	read(fd , in , SIZE);
	write(1 , in , SIZE	);
	}	 	
}
