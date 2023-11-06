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
        int fd = shm_open(NAME , O_CREAT | O_EXCL | O_RDWR , 0600);
        printf("%d",fd);
        if(fd < 0) {
                perror("shm_open()");
                return EXIT_FAILURE;
        }
		close(fd);
		shm_unlink(NAME);
}
