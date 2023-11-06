#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#ifndef PROTOCOL_H
#define PROTOCOL_H

#define NAME "/shared-mene"
#define NUM 50
#define SIZE (NUM * sizeof(char))
#endif

int main() {
	char buff[10] = "hemanth";
	char buff1[10] = "capgemini";
	int fd = shm_open(NAME , O_CREAT | O_EXCL | O_RDWR , 0600);
	if(fd < 0) {
		perror("shm_open()");
		return EXIT_FAILURE;
	}
	ftruncate(fd , SIZE);
	char *data =
	 (char*)mmap(0,SIZE, | PROT_WRITE, MAP_SHARED , fd , 0);
	printf("sender mapped address: %p\n" , data);
	strcpy(data , buff);
	printf("%s" , buff);
	strcpy(data+10 , buff1);
	printf("%s" , buff1);
	munmap(data , SIZE); 
	close(fd);
	return EXIT_SUCCESS;
}
	
