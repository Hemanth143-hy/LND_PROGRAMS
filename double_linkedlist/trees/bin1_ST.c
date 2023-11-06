#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right_child; 
    struct node *left_child; 
};

struct node* new_node(int x)
{
	struct node *root;
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;
    return p;
}
struct node* insert(struct node *root, int x)
{
     if(root==NULL)
        return new_node(x);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    return root;
}	
void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right_child);// visiting right child
    }

}
void Preorder(struct node *root) {
	if(root != NULL) {
		Preorder(root->right_child);
		Preorder(root->left_child);
		printf(" %d ", root->data);
	}
}
int main() {
	struct node *root;
	int n;
	int x;
	int i;
	printf("enter the no of nodes to be inserted:");
	scanf("%d",&n);
	for( i = 0 ; i < n; i++) {
		printf("enter the node to be inserted:");
		scanf("%d", &x);
    	root = new_node(x);
		insert(root , x);
	}
	/*
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root,45);
    insert(root,42);*/
   	inorder(root);
   	printf("\n");
	Preorder(root);
	printf("\n");
	return 0;
}
