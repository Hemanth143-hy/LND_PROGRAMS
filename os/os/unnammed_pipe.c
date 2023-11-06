#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

int main() {
	int fd[2];
	if (pipe(fd) == -1) {	
		printf("failed to open a pipe");
		exit(1);
	}
	int pid;
	pid = fork();
		if (pid == -1) {
			printf("the process is not created:");
			exit(1);
		}
	if( pid == 0 )  {
		close(fd[0]);
		FILE *ptr;
		char buff[SIZE];
		ptr = fopen("input_main.txt" , "r");
		fgets(buff , SIZE , ptr);
		close(fd[1]);
		fclose(ptr);
	}
}
