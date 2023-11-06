#include <stdio.h>
#include <stdlib.h>



int main()
{
    FILE *fptr1;
        FILE *fptr2;
    int count = 0;
    int ch;



       fptr1 = fopen("file1.txt", "a+");
        fptr2 = fopen("file2.txt", "a+");
    if ((fptr1 == NULL || fptr2 == NULL)) {
        printf("File does not exit\n");
        exit(1);
    } else {
        /*      printf("enter the Text : \n");
        while ((ch = getchar()) != EOF) {
                fputc(ch, fptr);
        } */
        while ((ch = fgetc(fptr1)) != EOF) {
                        fputc(ch, fptr2);
        }
                printf("files copied DONE !!!\n");
        fclose(fptr1);
                fclose(fptr2);
     }
     return 0;
}
