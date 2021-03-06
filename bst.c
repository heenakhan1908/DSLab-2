/*Description: Implementation of Binary Search Tree.
 Learner: Shiakh Mariyam Anis.
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	int data;
	struct bst *left,*right;
}node;

void insert(node**r,int num)
{
	node *temp,*ptr;
	temp=*r;
	if(temp==NULL)	
	{
		ptr=(node*)malloc(sizeof(node));
		ptr->data=num;
		ptr->left=NULL;
		ptr->right=NULL;
		*r=ptr;
	}
	else
	{
		if(num > temp->data)
		{
			if(temp->right==NULL)
			{
				ptr=(node*)malloc(sizeof(node));
				ptr->data=num;
				ptr->left=NULL;
				ptr->right=NULL;
				temp->right=ptr;
				return;
			}	
			else
			{
				temp=temp->right;
				insert(&temp,num);
			}			
		}
		else
		{
			if(temp->left==NULL)
			{
				ptr=(node*)malloc(sizeof(node));
				ptr->data=num;
				ptr->left=NULL;
				ptr->right=NULL;
				temp->left=ptr;
				return;
			}	
			else
			{
				temp=temp->left;
				insert(&temp,num);
			}			
		}
	}
}

void traverse_inorder(node*q)
{
	if(q!=NULL)
	{
		traverse_inorder(q->left);
		printf("%d\t",q->data);
		traverse_inorder(q->right);			
	}
}

int search_bst(node*q,int num)
{
	if(q==NULL)	
		return 0;
	else
	{
		if(q->data==num)
				return 1;
		else
		{
			if(num > q->data){
				search_bst(q->right,num);
			}	
			else
			{
				search_bst(q->left,num);
			}			
		}
	}
}

	
void delete(node**q,int num)
{
	node *temp;
	temp=*q;
	
	if(temp==NULL)	
	{
		printf("\n The given no. is not found");
		return;
	else
	{
		if(temp->data==num)
		{
			if(temp->left==NULL&&temp->right==NULL)
				free(temp);
			else
			{
				if
			return 1;
		else
		{
			if(num > q->data){
				delete(q->right,num);
			}	
			else
			{
				delete(q->left,num);
			}			
		}
	}
}



 
int main()
{
	node*root;
	root=NULL;
	insert(&root,5);
	insert(&root,6);
	insert(&root,7); 		
    traverse_inorder(root);
    if(search_bst(root,9)==1)
    {
		printf("\n the %d is present",9);
	}
	else
	    printf("\n not found");
    return 0;
}    
