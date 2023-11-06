#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
int main()
{
	DIR *mydir;
	time_t t;
	time(NULL);
	struct tm tm ;
	struct dirent *myfile;
	struct stat mystat;
	mydir = opendir(".");
	printf("SIZE\tNAME\tFILENAME\tTIME\tDATE\n");
	while((myfile = readdir(mydir)) != NULL) {
		stat(myfile->d_name, &mystat);
		printf("%-5ld\t",mystat.st_size);
		printf("%-5s\t", myfile->d_name);
		printf("%-5s\t",st_mtime);
	}
	closedir(mydir);
}
