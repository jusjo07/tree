#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(int val)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=val;
	new->left=NULL;
	new->right=NULL;
	return(new);
};

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d\t", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	printf("%d\t", root->data);
	postorder(root->right);
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	inorder(root->right);
	printf("%d\t", root->data);
}

void main()
{
	struct node *root;
	int ch;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->right->right=newnode(5);
	root->right->left=newnode(6);
	printf("\n\nMAIN MENU\n1.Preorder Traversal\n2.Postorder traversal\n3.Inorder Traversal\n");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
					 preorder(root);
					 break;
				}
			case 2: {
					 postorder(root);
					 break;
				}
			case 3: {
				 	inorder(root);
					break;
				}
			default: {
					printf("\nWrong Choice!\n");
					exit(0);
				}
		}
	}
}

