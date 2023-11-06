#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;	
	struct Node *left;
	struct Node *right;
	} ;
void Create_Node(int x);
void Insert_Node(struct Node *root , int x);
int x;
struct Node *root;
struct Node *temp;
int main()  {
	/*
	printf("enter the data to create the node:");
	scanf("%d",&x);
	Create_Node(x);
	Insert_Node(x);*/
	struct Node *root =  NULL;
	root = Insert_Node(root,15);
	root = Insert_Node(root,10);	
	root = Insert_Node(root,20);
	root = Insert_Node(root,25);
	root = Insert_Node(root,8);
	root = Insert_Node(root,12);
}
void Create_Node(int x) {
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->left = temp->right = NULL;
	return temp;
}
void Insert_Node( struct Node *root ,int x) {
//	root = Create_Node(x);
	if(root == NULL) {
		root = Create_Node(x);
	} else if(x <= root->data) {
		root->left = Insert_Node(root->left , x);
	} else {
		root->right = Insert_Node(root->right , x);
	}
	return root;
}


	
