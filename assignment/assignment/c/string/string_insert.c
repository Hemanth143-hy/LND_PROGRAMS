#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20
char* strrem(char *str, char *sstr);
int main()
{
        char *str;
        char *sstr;
        str = (char *) malloc (SIZE * sizeof(char));
        sstr = (char *) malloc (SIZE * sizeof(char));
        if (NULL == str && NULL == sstr) {
                printf("malloc failed!!\n");
                exit(0);
        }
        printf("Enter the String: \n");
        if (NULL == (fgets(str, SIZE, stdin))) {
                printf("Fgets failed for str");
        }
        printf("Enter the sub String: \n");
        if (NULL == (fgets(sstr, SIZE, stdin))) {
                printf("Fgets failed for sstr");
        }
        *(str + (strlen(str)) - 1) = '\0';
        *(sstr + (strlen(sstr)) - 1) = '\0';
        printf("String is %s\n", strrem(str, sstr));
        free(str);
        free(sstr);
        str = NULL;
        sstr = NULL;
}



char* strrem(char *str, char *sstr)
{
        char *temp = str;
        int count = 0;
        while (*str) {
                if (*str == *sstr) {
                        while (*sstr) {
                                if (*str == *sstr) {
                                        count++;
                                        if (strlen(sstr) == count) {
                                                *str++;
                                                while (*str) {
                                                   *(str) = *((str-1) - strlen(sstr));
                                                        *str++;
                                                }
                                                break;
                                        }
                                } else {
                                        break;
                                }
                                *str++;
                                *sstr++;
                        }
                }
                *str++;
        }
        return temp;
}
