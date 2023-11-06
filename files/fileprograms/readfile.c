#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
		printf("Error in creating"
