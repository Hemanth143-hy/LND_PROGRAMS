#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFFER_SIZE 25
#define BUFFER_SIZE1 25
#define READ_END 0
#define READ_END1 0
#define WRITE_END 1
#define WRITE_END1 1
int main(void)	{ 
	char write_msg[BUFFER_SIZE] ;
//	char write_msg1[BUFFER_SIZE1] ;
	char read_msg[BUFFER_SIZE];
//	char read_msg1[BUFFER_SIZE];
	int fd[2];
//	int fd1[2];
	pid_t pid;
	/* create the pipe */
	printf("enter the data to read from parent to child:");
	fgets( write_msg , BUFFER_SIZE , stdin);
	write_msg[strlen(write_msg) - 1] = '\0';
	printf("%s\n", write_msg);	
	if (pipe(fd) == -1) { 
		fprintf(stderr,"Pipe failed");	
//		printf("%d", fd);
	return 1;
	}
	if(pipe(fd1) == -1) {
		fprintf(stderr , "Pipe failed");
	return 1;
	}
	/* fork a child process */
//	printf("%d\n" ,getppid()); ,
	pid = fork();
//	printf("%d\n" , getppid());	
//	printf("%d\n" , getpid());
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
	return 1;
	}
	if (pid > 0) { /* parent process */
	/* close the unused end of the pipe */
		close(fd[WRITE_END1]);
		read(fd1[READ_END1], read_msg1, BUFFER_SIZE1);
		printf("parent:%s" , read_msg1);
		close(fd1[READ_END1]);		
		close(fd[READ_END]);
	/* write to the pipe */
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
	/* close the write end of the pipe */
		close(fd[WRITE_END]);
	} else {
	 /* child process */
	/* close the unused end of the pipe ;*/
		printf("enter the data to parent from child:");
		fgets ( write_msg1 , BUFFER_SIZE1 , stdin);
		write_msg1[strlen(write_msg1) - 1] = '\0';	
		printf("%s",write_msg1);
		close(fd1[READ_END1]);
		write(fd1[WRITE_END1],write_msg1, strlen(write_msg1)+1);
		close(fd1[WRITE_END1]);
		close(fd[WRITE_END]);
	/* read from the pipe */
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("child %s", read_msg );
	/* close the write end of the pipe */
		close(fd[READ_END]);
	}
	return 0;
}
