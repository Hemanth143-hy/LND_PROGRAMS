#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
void usrmode(int);
void grpmode(int);
void othmode(int);
int main()
{
    struct stat get;
    struct passwd *userid;
    struct group *groupid;
    char *timp;
    struct tm tim;
    time_t t = time(NULL);
    char dirname[100];
    DIR*openfd;
    int permission;
    struct dirent *readfd;
    char *str;
    int n;
    int sum = 0;
    const long int time;
    getcwd(dirname, 100);
    openfd = opendir(".");
    if(openfd == NULL) {
        printf("Error");
    exit(1);
    }
    while((readfd=readdir(openfd)) != NULL) {
        stat(readfd -> d_name, &get);
        n = get.st_blocks;
        sum = sum + n/2;
    }
    printf("total %d\n",sum);
    closedir(openfd);
    openfd = opendir(".");
    if(openfd == NULL) {
        printf("Error");
        exit(1);
    }
    while((readfd=readdir(openfd)) != NULL) {
        stat(readfd -> d_name, &get);
        if (readfd -> d_type == DT_DIR) {
            printf("d");
        } else {
            printf("-");
        }
        permission = get.st_mode;
        usrmode(permission);
        grpmode(permission);
        othmode(permission);
        printf(" %-3ld",get.st_nlink);
        userid = getpwuid(get.st_uid);
        printf(" %-4s", userid->pw_name);
        groupid = getgrgid(get.st_gid);
        printf(" %-4s", groupid->gr_name);
        printf(" %-6ld", get.st_size);
        str = ctime(&get.st_mtim);
        *(str+strlen(str)-9) = '\0';
        printf("\t%s",str+4);
        if (readfd -> d_type == DT_DIR) {
            printf("\033[0;34m");
            printf("\t%s",readfd->d_name);
            printf("\033[0m");
        } else if ((readfd -> d_type != DT_DIR) && (permission & (1 << 6))) {
            printf("\033[0;32m");
            printf("\t%s",readfd->d_name);
            printf("\033[0m");
        } else {
            printf("\t%s",readfd->d_name);
        }
        printf("\n");
    }
    closedir(openfd);
    return 0;
}
void usrmode(int permission)
{
    int num = permission;
    if (num & (1 << 8)) {
        printf("r");
    } else {
        printf("-");
    }
    if (num & (1 << 7)) {
        printf("w");
    } else {
        printf("-");
    }
    if (num & (1 << 6)) {
        printf("x");
    } else {
        printf("-");
    }
}
void grpmode(int permission)
{
    int num = permission;
    if (num & (1 << 5)) {
        printf("r");
    } else {
        printf("-");
    }
    if (num & (1 << 4)) {
        printf("w");
    } else {
        printf("-");
    }
    if (num & (1 << 3)) {
        printf("x");
    } else {
        printf("-");
    }
}
void othmode(int permission)
{
    int num = permission;
    if (num & (1 << 2)) {
        printf("r");
    } else {
        printf("-");
    }
    if (num & (1 << 1)) {
        printf("w");
    } else {
        printf("-");
    }
    if (num & 1) {
        printf("x");
    } else {
        printf("-");
    }
}
