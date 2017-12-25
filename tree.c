/*
 ============================================================================
 Name        : ml.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
//struct node* root;

struct node* newnode(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));

	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return (temp);
}
struct node* insert( struct node* root,int data)
{
	if (root==NULL)
	{
		root=newnode(data);
		return root;
	}
	else if(data<=root->data)
	root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}

void traversal(struct node* root)
{
	if(root==NULL)
		return;
	else
		printf("%d ",root->data);
	traversal(root->left);
	traversal(root->right);

}

int main()
{
	struct node* root=NULL;
	root=insert(root,15);
	root=insert(root,20);
	root=insert(root,10);
	root=insert(root,30);
	root=insert(root,5);
	root=insert(root,8);
	root=insert(root,50);

	traversal(root);
	return 0;
}


