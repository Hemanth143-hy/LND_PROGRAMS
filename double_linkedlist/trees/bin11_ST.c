#include<stdio.h>
#include<stdlib.h>
struct Node {
        int data;
        struct Node* left;
        struct Node* right;
        };
struct Node *root;
struct Node *create(struct Node *root, int data);
int search(struct Node *root, int key, int i);
void display(struct Node* root);
struct Node *insert(struct Node* root, int num);
struct Node *count(struct Node *root);
int main()
{
        int ch;
        int data;
        int key;
        int i;
        int num;
        int c;
        int j;
        root = NULL;
        while (1) {
                printf("\n1.create\n2.inorder\n3.exit\n4.search\n5.insert\n");
                scanf("%d", &ch);
                switch (ch) {
                	case 1:
                    		while (1) {
                        		printf("enter data\n");
                            	scanf("%d", &data);
                            	root = create(root,data);
                            	printf("1 for insert 0 for exit\n");
                            	scanf("%d", &j);
                            	if (j == 0) {
                            	break;
                            	} else {
                            	continue;
                             		}
                            	}	
                        break;
                        case 2:
                                display(root);
                        break;
                        case 3:
                                exit(1);
                        break;
                        case 4:
                                printf("Enter data you want to search\n");
                                scanf("%d", &key);
                                i = search(root,key,i);
                                if (i == 0) {
                                        printf("data is not found\n");
                                } else {
                                        printf("data is found\n");
                                }
                        case 5:
                                printf("enter new data\n");
                                scanf("%d", &num);
                                root = insert(root, num);
                                break;
                        default:
                                printf("Enter correct choice");
                        break;
                }
        }
}
struct Node *create(struct Node *root, int data)
{
        if (root == NULL) {
                struct Node *newnode = (struct Node*) malloc (sizeof(struct Node));
                newnode->data = data;
                newnode->left = NULL;
                newnode->right = NULL;
                return newnode;
        }
        if (data < root->data) {
                root->left = create(root->left, data);
        } else if(data > root->data) {
                root->right = create(root->right, data);
                }
        return root;
}
int search(struct Node* root, int key, int i)
{
//      int key;
        if (root == NULL) {
                return 0;
        }
        if (root != NULL) {
                if (key == root->data) {
                        return 1;
                }
                if (key < root->data) {
                        return search(root->left, key, i);
                }
                if (key > root->data) {
                        return search(root->right, key, i);
                }
        }
}
struct Node *insert (struct Node *root, int num)
{
        if (root == NULL) {
                struct Node *temp;
                temp = (struct Node *) malloc (sizeof(struct Node));
                temp->data = num;
                temp->left = NULL;
                temp->right = NULL;
                return temp;
        }
        if (num < root->data) {
                root->left = insert(root->left, num);
        }
        if (num > root->data) {
                root->right = insert(root->right, num);
        }
        return root;
}
void display(struct Node *root)
{
        if (root != NULL) {
                display(root->left);
                printf("%d->", root->data);
                display(root->right);
        }
}

