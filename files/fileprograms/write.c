#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
struct employee {
        char name[20];
        int id;
        int age;
        float sal;
};
int main()
{
    int empNo;
    FILE *fptr = NULL;
	struct employee *emp;
    fptr = fopen("emp_details.dat","wb");
    if(fptr == NULL) {
        printf("Error in file opining - \n");
        exit(1);
    }
    emp = (struct employee*)malloc (sizeof(struct employee));
    printf("Enter employee name -\n");
//    fgets(emp->name, 20, stdin);
	scanf("%s",emp->name);
   // *(emp.name + (strlen(emp.name) - 1)) = '\0';
    printf("Enter employee Id -\n");
    scanf("%d", &emp->id);
    printf("Enter employee Age -\n");
    scanf("%d", &emp->age);
    printf("Enter employee Salary -\n");
    scanf("%f", &emp->sal);
    fwrite(emp, sizeof( struct employee), 1,fptr);
    fclose(fptr);
    return 0;
}
