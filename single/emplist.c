#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define SIZE 20
struct employe {
	char *name ;
	char gender  ;
	float sal;
	struct employe* next;
	} e1, e2 , e3;
void display_fun(struct employe* temp);
int main()
{	
	struct employe* start;
	struct employe* mid;
	struct employe* end;
	e1.name = (char *)malloc(SIZE * sizeof(char));
	e2.name = (char *)malloc(SIZE *sizeof(char));	
	e3.name = (char *)malloc(SIZE *sizeof(char));
	start =(struct employe*)malloc(sizeof(struct employe)); 
	mid = (struct employe *)malloc(sizeof(struct employe));
	end = (struct employe *)malloc(sizeof(struct employe));
	__fpurge(stdin);
	printf("enter the name :");
	fgets(e1.name, SIZE, stdin);
		*(e1.name + (strlen(e1.name) -1 )) = '\0';
	start->name = e1.name;
	printf("enter the gender:");
	scanf("%c",&start->gender);
	printf("enter the salary:");
	scanf("%f",&start->sal);
	start ->next = mid;

	__fpurge(stdin);
	printf("enter the name of emp:");
	fgets(e2.name, SIZE , stdin);
		*(e2.name + (strlen(e2.name) -1 )) = '\0';
	mid->name = e2.name;
	printf("enter the gender:");
	scanf("%c",&mid->gender);
	printf("enter the salary:");
	scanf("%f",&mid->sal);
	mid ->next = end;

	__fpurge(stdin);
	printf("enter the name of emp:");
	fgets(e3.name, SIZE , stdin);
		*(e3.name + (strlen(e2.name) -1 )) = '\0';
	end->name = e3.name;
	printf("enter the gender:");
	scanf("%c",&end->gender);
	printf("enter the salary:");
	scanf("%f",&end->sal);
	end ->next = NULL;
	display_fun(start);
}
void display_fun(struct employe* temp)
{
	printf("Name\tgender\tsalary\t\n");
	while(temp != NULL) {
		printf("\n%s %.2f ",temp->name ,  temp-> sal);
	if(temp->gender == '0' ) {
		printf("male");
	} else if (temp->gender == '1') {
		printf("female");
	} else {
		printf("others");
	}
		temp = temp->next;
	}
}

	
	
