#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
struct employee {
        char name[20];
        int id;
        int age;
        float sal;
} emp;
int main()
{
	char *ptr1;
	int i;
    int empNo;
    FILE *fptr = NULL;
    fptr = fopen("emp_details.dat","w");
    if(fptr == NULL) {
    	printf("Error in file opining - \n");
        exit(1);
    }
	ptr1 = (struct emp*)malloc (sizeof( struct emp));
    printf("Enter No of Employee -\n");
    scanf("%d", &empNo);
    for(i = 0; i < empNo; i++) {
     __fpurge(stdin);
    printf("Enter employee name%d -\n", i+1);
    fgets(emp.name, 20, stdin);
    *(emp.name + (strlen(emp.name) - 1)) = '\0';
    printf("Enter employee Id%d -\n", i+1);
    scanf("%d", &emp.id);
    printf("Enter employee Age%d -\n", i+1);
    scanf("%d", &emp.age);
    printf("Enter employee Salary%d -\n", i+1);
    scanf("%f", &emp.sal);
    fwrite(&emp, sizeof(emp), 1,(ptr1));
    }
	fclose(fptr);
/*
    fseek(fptr, 0, SEEK_SET);
    printf("\nNAME\tEMP_ID\tAGE\tSALARY\n");
    while(fread(&emp1, sizeof(emp1), 1, fptr) == 1) {
    printf("%s\t", emp1.name);
    printf("%d\t", emp1.id);
    printf("%d\t", emp1.age);
    printf("%f\n", emp1.sal);
    }
    fclose(fptr);i
*/
    return 0;
}
