#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX 128

int main()
{
    int fd[2];
    if (pipe(fd) == -1) {
        printf("error in creating file\n");
        exit(1);
    }
    int pid;
    pid = fork();
       if (pid == -1) {
        printf("error in creating file\n");
        exit(1);
       }
	if (pid == 0) {
		close(fd[0]);
        FILE *fptr;
        char buff[MAX];
        fptr = fopen("input.txt", "r");
		printf("enter the data:");
		fgets(buff , MAX , stdin);
		fprintf(fptr ,"%s" , buff);	
        if (write(fd[1], buff, MAX) == -1) {
            printf("error at write in pipe\n");
            exit(1);
           }
        close(fd[1]);
        fclose(fptr); 
     } else {
         wait(NULL);
        close(fd[1]);
        FILE *fpptr;
        char pbuff[MAX];
        fpptr = fopen("output.txt", "w+");
        if ( read(fd[0], pbuff, MAX) == -1) {
            printf("error at reading in pipe\n");
        }
        printf("the msg from parent:%s\n", pbuff);
        fprintf(fpptr, "%s", pbuff);
        close(fd[0]);
        fclose(fpptr);
     }
}
