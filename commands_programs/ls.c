#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main()
{
	DIR *mydir;
	struct dirent *myfile;
	struct stat mystat;
	mydir = opendir(".");
//	printf("NAME\n");
	while((myfile = readdir(mydir)) != NULL) {
		stat(myfile->d_name, &mystat);
//		printf("%-5ld\t",mystat.st_size);
		printf("%-5s\t", myfile->d_name);
//		printf("%-5ld\t", myfile->d_ino);
//		printf("%-5u\t", myfile->d_reclen);;
//		printf("%-5\n", myfile->d_name[100]);
	
	}
	closedir(mydir);
}
