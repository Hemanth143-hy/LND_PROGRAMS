#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
int close(int fd);
//new write(int fd, char buf, size_t cnt);
int main()
{
	int new;

	int fd;
	char buf[15] ="hello world"; 
//	printf("enter the string data:");
//	fgets(buf , strlen(buf) , stdin);
	fd = open("hello.txt", O_RDWR | O_CREAT);
	printf("The  file discripter no is :%d\n",fd);
//	new = read(fd , buf , strlen(buf));
	new = write(fd , buf , strlen(buf));
	printf("characters written :%s\n",buf);
//	new = read(fd , &buf , 10);
//	printf("");
	if(close(fd) == '\0') {
		printf("The file is closed");
	}
	
}
