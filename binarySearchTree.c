#include<stdio.h>
#include<stdlib.h>

typedef
struct bst{
	int data;
	struct bst*left,*right;
}node;

void traverse_inorder(node *r)
{
	if(r!=NULL){
		traverse_inorder(r->left);
		printf("%d\t",r->data);
		traverse_inorder(r->right);
}		

void insert(node **r,int num){
	node *temp,*ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=num;
	ptr->left=NULL;
	ptr->right=NULL;
	temp=*r;
	if(temp==NULL)
		*r=ptr;
	else{
		if(num > temp->data){
			if(temp->right!=NULL)
				insert(&temp->right,num);
			else
				temp->right=ptr;
			} 		
		else
		{
			if(temp->left!=NULL)
				insert(&temp->left,num);	
			else
				temp->left=ptr;
		}
	}
}						

void search_node(node **x,node*root,node**parent,int num,int*f)
{
	node *temp;
	temp=root;
	if(temp==NULL)
		return;
	while(temp!=NULL)
	{
		if(temp->data==num)
	  {
		*f=1;
		*x=temp;
		return;
	  }
		*parent=temp;
		if(num>temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}	


void delete(node **r,int num)
{
	node *temp,*parent,*x,*xsucc;
	int f=0;
	parent = NULL; x=NULL; xsucc=NULL;
	temp=*r;
	search_node(&x,temp,&parent,num,&f);
	if(temp==NULL)
		return;
	search_node(num,&parent,&x,&xsucc,&f);
	if(f==0)
	{
		printf("\n THe node is not found");
		return;
	}	
	// x has no child
	if(x->left==NULL && x->right==NULL)
	{
	        if(x->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
			
	}	
	else if(x->left!=NULL && x->right==NULL)
	{
		
	        if(x->data > parent->data)
			parent->right=x->left;
		else
			parent->left=x->left;
			
	}		
	
	else if(x->right!=NULL && x->left==NULL)
	{
		
	        if(x->data > parent->data)
			parent->right=x->right;
		else
			parent->left=x->right;
			
	}		
	else if(x->right!=NULL && x->left!=NULL)
	{
		xsucc=x->right;
		parent = x;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		x->data=xsucc->data;
		x=xsucc;
		if(xsucc->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
	}	
	free(x);		
}	

int search_bst(node *r,int num){
	if(r==NULL){
		return 0;
	else{
		if(num==r->data)
			return 1;
		else{
			if(num> r->data){
				return search_bst(r->right,num);
			}		
			else{
				return search_bst(r->left,num);
			}
		}
}			

void main()
{
	node *root;
	root=NULL;
	int ch,d;
	
	printf("ENTER YOUR CHOICE \n")
	printf("MENU \n1.INSERT \n 2.DELETE \n 3.TRAVERSE 4.SEARCH \n 5.EXIT ")
	scanf("%d",&ch)
	switch(ch)
	{
		case 1:
				printf("\nENTER THE NUMBER TO BE INSERTED: ");
				scanf("%d",&no);
				insert(&root,no);
		case 2:
				printf("\nENTER THE NUMBER TO BE DELETED: ");
				scanf("%d",&no);
				delete(&root,no);
				break;
		case 3: printf("ENTER THE No. TO BE SEARCHED: ");
				scanf("%d"&no);
				
	}	
}			
