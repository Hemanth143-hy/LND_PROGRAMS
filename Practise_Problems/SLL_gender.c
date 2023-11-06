#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stddef.h>
struct Node
{
        int id;
        char name[50];
        char lname[50];
        char gender[12];
        char occupation[50];
        int age;
        struct Node* next;
};
struct Node  *create(struct Node *head1,struct Node *head2 , FILE *fp);
void printList(struct Node *head1);
void printList2(struct Node *head2);
void freelist(struct Node *head1);
int main()
{
        FILE *fp = NULL;
        struct Node* head1 = NULL;
		struct Node* head2 = NULL;
        fp = fopen("Club_Membership_2020.txt", "r");
        if (fp == NULL)
        {
                printf("Error! Could not read the file.");
            exit(1);
        }
        head1 = create(head1,head2, fp);
        printList(head1);
		printList2(head2);
        fclose(fp);
        freelist(head1);
        head1 = NULL;
        return 0;
}
struct Node *create(struct Node *head1, struct Node *head2,  FILE *fp)
{
        struct Node mem;
        while (fscanf(fp, "%d %s %s %s %s %d", &mem.id, mem.name,mem.lname, mem.gender, mem.occupation, &mem.age) != EOF)  {
			  // if(head1->gender[0] == 'M'){
                struct Node* newNode;	
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode -> id = mem.id;
                strcpy(newNode -> name, mem.name);
                strcpy(newNode->lname, mem.lname);
                strcpy(newNode -> gender, mem.gender);
                strcpy(newNode -> occupation, mem.occupation);
                newNode -> age = mem.age;
                newNode -> next = NULL;
				if(newNode->gender[0] == 'M') {
                	if(head1 == NULL) {
                        head1 = newNode;
                	} else {
                        struct Node *temp = NULL;
                        temp = head1;
                        while(temp->next != NULL) {
                                temp = temp->next;
                        }
                        temp->next = newNode;
                  }
				} else  {
					if(newNode->gender[0] == 'F') {
                		if(head2 == NULL) {
                        head2 = newNode;
                	} else {
                        struct Node *temp = NULL;
                        temp = head2;
                        while(temp->next != NULL) {
                                temp = temp->next;
                        }
                        temp->next = newNode;
                  }

			}
			//printList2(head2);
		}
		return head1;
	}
	return head2;	
//	return head1;
}
void printList(struct Node *head1)
{
       if (head1 == NULL) {
                printf("List is empty!");
        } else {
        while (head1 != NULL) {
//		if(head1 -> gender[12] != "MALE") {
       	 		printf("%d\t", head1->id);
        		printf("%-10s\t", head1->name);
        		printf("%-10s\t", head1->lname);
        		printf("%-10s\t", head1->gender);
       			printf("%-10s\t", head1->occupation);
        		printf("%d\t", head1->age);
        		head1 = head1->next;
        		printf("\n");
 //              } else {
//			return ;
//			}				
        }
	}
}
void printList2(struct Node *head2)
{
       if (head2 == NULL) {
                printf("List is empty!");
        } else {
        while (head2 != NULL) {
//		if(head1 -> gender[12] != "MALE") {
       	 		printf("%d\t", head2->id);
        		printf("%-10s\t", head2->name);
        		printf("%-10s\t", head2->lname);
        		printf("%-10s\t", head2->gender);
       			printf("%-10s\t", head2->occupation);
        		printf("%d\t", head2->age);
        		head2 = head2->next;
        		printf("\n");
 //              } else {
//			return ;
//			}				
        }
	}
}
void freelist(struct Node *head1)
{
        struct Node *temp;
        while(head1 != NULL) {
                temp = head1;
                head1 =  head1 -> next;
                free(temp);
                temp = NULL;
        }
}
