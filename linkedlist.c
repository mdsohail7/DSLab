#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list{
	int data;
	struct linked_list * next;
}node;

void print(node *q)
{
	node *ptr;
	ptr=q;
	printf("\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}

void insbeg(node **q,no)
{
	node *temp,*ptr;
	temp=*q;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=no;
	if(temp==NULL)
			ptr->next=NULL;
	else
			ptr->next=temp;
	*q=ptr;
	printf("\nElements of linkedList after insertion \n");
	printf(*q);
}

void insend(node **q, int no)
{
	node *ptr,*temp;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=no;
	ptr->next=NULL;
	temp=*q;
}

void insafter(node *q,int no)
{
	int loc,k;
	node *temp,*ptr,*old;
	temp=q;
	ptr=(node*)malloc(sizeof(node*));
	ptr->data=no;
	printf("ENTER LOCATION WHERE NO. IS TO BE INSERTED: ");
	scanf("%d",&loc);
	for(k=1;k<loc;k++)
	{
		if(temp==NULL)
			printf("\nElements are less than provided loacation \n");
		else
		{
			old=temp;
			temp=temp->next;
		}
	}
	ptr->next=temp;
	old->next=ptr;
	printf("\n Elements of LInkLIst after insertion \n");
	printf(q);
}

void del(node **q,int no)	
{
	int f=0;
	node *old,*temp;
	temp=*q;
	
	while(temp!=NULL)
	{
		if(temp->data==no)
		{
			f=1;
			if(temp==*q)
				*q=temp->next;
			else
				old->next=temp->next;
			free(temp);
			break;
		}
		else
		{
			old=temp;
			temp=temp->next;
		}
	}
	
	if(f==0)
		printf("\n The given no. is not found \n");
		
	printf("\n Elements of linked list after deletion \n");
	print(*q);	
}	

int main()
{	
	node *start,*ptr,*temp;
	int i,n,j,no,c;
	printf("Enter No. of nodes: ");
	scanf("%d",&n);
	printf("\n Enter node no. 1: ");
	start(node*)malloc(sizeof(node));
	scanf("%d",&start->data);
	temp=start;
	for(i=1;i<n;i++)
	{
		ptr=(node*)malloc(sizeof(node));
		printf("\n Enter nod number %d: ",i+1);
		scanf("%d",&ptr->data);
		temp->next=ptr;
		temp=ptr;
	}
	temp->next=NULL;
	do{
		printf("\nEnter your choice\n");
		printf("\n1-INsertion\n3-Deletion\n3-TRaverse\n4-Exit\n");
		scanf("%d",&j);
		switch(j)
		{
			case 1:
					printf("\n Enter the number to be inserted: ");
					scanf("%d"&no);
					printf("\n Enter 1 to insert at the begining \n");
					printf("\n Enter 2 to insert at the end \n");
					printf("\n Enter 3 to insert at specified location \n");
					scanf("%d"&c);
					switch(c)
					{
						case 1:
							insbeg(&start,no);
							break;
						case 2:
							insend(&start,no);
							break;
						case 3:
							insafter(start,no);
							break;
						default:
							printf("\n Invalid Choice.");
					}
					break;
			case 2:
					printf("\n Enter the no. to be deleted: ");
					scanf("%d",&no);
					del(&start,no);
					break;
			case 3:
					traverse(start);
					break;
			case 4:
					exit(0)
			default:
					printf("\n Invalid Input");
					break;
			}		
	
	return 0;
}		
