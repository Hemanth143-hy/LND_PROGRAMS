#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee {
	char name[20];
	int id;
	int age;
	float sal;
	};
int main()
{	
	struct employee emp;
	FILE *fptr = NULL;
	fptr = fopen("emp_details.dat","rb");
	if(fptr == NULL) {
		printf("Error in the file opening \n");
		exit(1);
	}
	while(fread(&emp ,sizeof(struct employee) , 1 , fptr) == 1) {
//	printf("\nNAME\tEMP_ID\tAGE\tSALARY\n");
	printf("%s\t", emp.name);
	printf("%d\t", emp.id);
	printf("%d\t", emp.age);
	printf("%f\n", emp.sal);
	}
	fclose(fptr);
}
	
