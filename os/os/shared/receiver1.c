#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#ifndef PROTOCOL_H
#define PROTOCOL_H

#define NAME "/shared-mene"
#define NUM 50
#define SIZE (NUM * sizeof(int))
#endif

int main() {
	int fd = shm_open(NAME , O_RDWR , 0666);
	if(fd < 0) {
		perror("shm_open()");
		return EXIT_FAILURE;
	}
	char *data =
	 (char*)mmap(0,SIZE,PROT_READ,  MAP_SHARED , fd , 0);
	printf("receiver mapped address: %p\n" , data);
	printf("%s\n", data+10);
	munmap(data , SIZE);
	close(fd);
//	shm_unlink(NAME);
	return EXIT_SUCCESS;
}
	
