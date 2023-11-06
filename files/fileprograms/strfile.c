#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
struct employee {
        char name[20];
        int id;
        int age;
        float sal;
} emp1;




int main()
{
        int i;
        int empNo;



       FILE *fptr = NULL;
        fptr = fopen("emp_details.dat","wb+");
        if(fptr == NULL) {
                printf("Error in file opining - \n");
                exit(1);
        }
        printf("Enter No of Employee -\n");
        scanf("%d", &empNo);



       for(i = 0; i < empNo; i++) {
                 __fpurge(stdin);
                printf("Enter employee name%d -\n", i+1);
                fgets(emp1.name, 20, stdin);
                *(emp1.name + (strlen(emp1.name) - 1)) = '\0';
                printf("Enter employee Id%d -\n", i+1);
                scanf("%d", &emp1.id);
                printf("Enter employee Age%d -\n", i+1);
                scanf("%d", &emp1.age);
                printf("Enter employee Salary%d -\n", i+1);
                scanf("%f", &emp1.sal);
                fwrite(&emp1, sizeof(emp1), 1, fptr);
        }
        fseek(fptr, 0, SEEK_SET);
        printf("\nNAME\tEMP_ID\tAGE\tSALARY\n");
        while(fread(&emp1, sizeof(emp1), 1, fptr) == 1) {
                printf("%s\t", emp1.name);
                printf("%d\t", emp1.id);
                printf("%d\t", emp1.age);
                printf("%f\n", emp1.sal);
        }



       fclose(fptr);
       return 0;



}
