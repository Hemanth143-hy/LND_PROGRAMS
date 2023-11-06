#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

#define SIZE 100

int main() {	
//	int mkfifo;
    int	*myfifo;
	myfifo = mkfifo("" , 0666);	
	int fd[2];
	FILE *fptr;	
	char buff[SIZE];
	fptr = fi
