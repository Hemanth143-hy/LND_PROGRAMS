#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};
int val;
void preOrder(struct node* root);
void PostOrder(struct node* root);
void InOrder(struct node* root);
int main() {
	struct node *p1 , *p2 ,*p3 , *p4 , *p5 , *p6;
	p1 = (struct node*)malloc(sizeof(struct node));
	p2 = (struct node*)malloc(sizeof(struct node));
	p3 = (struct node*)malloc(sizeof(struct node));
	p4 = (struct node*)malloc(sizeof(struct node));
	p5 = (struct node*)malloc(sizeof(struct node));
	p6 = (struct node*)malloc(sizeof(struct node));
	printf("enter the data to p1:");
	scanf("%d",&val);
	p1->data = val;
	printf("enter the data to p2:");
	scanf("%d",&val);
	p2->data = val;
	printf("enter the data to p3:");
	scanf("%d",&val);
	p3->data = val;
	printf("enter the data to p4:");
	scanf("%d",&val);
	p4->data = val; 
	printf("enter the data to p5:");
	scanf("%d",&val);
	p5->data = val;
	printf("enter the data to p6:");
	scanf("%d",&val);
	p6->data = val;
	p1->left = p2 ;
	p1->right = p3 ;
	p3->left = p4 ;
	p3->right = p5 ;
	p2->left = p6;
	p2->right = NULL;
	p4->left = NULL;
	p4->right = NULL;
	p5->left = NULL;
	p5->right = NULL;
	p6->right = NULL;
	p6->left = NULL;
	printf("preorder:");
	preOrder(p1);
	printf("\npostorder:");
	PostOrder(p1);
	printf("\nInorder:");
	InOrder(p1);
	return 0;
}
void preOrder(struct node* root) {
	if(root != NULL) {
		printf("%d\t",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void PostOrder(struct node* root) {
	if(root != NULL) {
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d\t",root->data);
	}
}
void InOrder(struct node* root) {	
	if(root != NULL) {
		InOrder(root->left);
		printf("%d\t",root->data);
		InOrder(root->right);
	}
}
	
	
