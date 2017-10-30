#include<stdio.h>
#include<stdlib.h>

typedef struct dlinked_list
{
	int data;
	struct dlinked_list *next;
	struct dlinked_list *prev;
}node;

void print(node *q)
{
	node *ptr;
	ptr=q;
	printf("\n");
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
}

void insbeg(node **q,int no)
{
	node *temp , *ptr;
	temp=*q;
	ptr= (node*)malloc(sizeof(node));
	ptr->data=no;
	ptr->prev=NULL;
	if(temp==NULL)
		ptr->next=temp;
	else
	{
		ptr->next=temp;
		temp->prev=ptr;
	}
	*q=ptr;
	printf("\n ELEMENT OF LINKLIST AFTER INSERTION: \n");
	print(*q);
}

void insend(node **q,int no)
{
	node *ptr,*temp;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=no;
	ptr->next=NULL;
	temp=*q;
	if(temp==NULL)
		*q=ptr;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ptr;
	}
	ptr->prev=temp;
	printf("\n ELEMENT OF LINKLIST AFTER INSERTION: \n");
	print(*q);
}

void insafter(node *q, int no)
{
	int loc,k;
	node *temp,*ptr;
	temp=q;
	ptr=(node*)malloc(sizeof(node*));
	ptr->data=no;
	printf("\n Enter The Location Where The No. Is To Be Inserted: \n");
	scanf("%d",&loc);
	if(loc==1)
	{
		printf("\n Please Enter a Number At Begining Portion \n");
		return;
	}
	for(k=1;k<loc;k++)
	{
		if(temp==NULL)
			printf("\n ELEMENT ARE LESS THAN PROVIDED LOCATION \n");
		else
		{
			temp=temp->next;
		}
	}
	ptr->next=temp;
	temp->prev->next=ptr;
	ptr->prev=temp->prev;
	temp->prev=ptr;
	printf("\n ELEMENT OF LINKLIST AFTER INSERTION: \n");
	print(q);
}

void del(node **q,int no)
{
	int f=0;
	node *temp;
	temp=*q;

	while(temp!=NULL)
	{
	     if(temp->data==no)
	     {
			 f=1;
			 if(temp==*q)
			 {
			     *q=temp->next;
			 }
			 else
			  {
				  temp->prev->next=temp->next;
				  if(temp->next!=NULL)
					temp->next->prev=temp->prev;

		  }
		  printf("\n Element %d Deleted Successfully\n",temp->data);
				  free(temp);
				  break;
		  }
		  else
		  {
			  temp=temp->next;
		  }


	if(f==0)
		printf("\n THE GIVEN NUMBER IS NOT FOUND \n");

	printf("\n ELEMENT OF LINKLIST AFTER DELETION \n");
	print(*q);
}
}

void traverse (node*q)
{
	printf("\n TRAVERSING LINKLIST  \n");
	print(q);
	printf("\n END OF LINKLIST  \n");
}

int main ()
{
	node *start,*ptr,*temp;
	int i,j,n,c;
	printf("\n Enter Number Of Nodes:\t");
	scanf("%d",&n);
	printf("\n Enter Node Number 1:\t");
	start=(node*)malloc(sizeof(node));
	scanf("%d",&start->data);
	start->prev=NULL;
	temp=start;
	for(i=1;i<n;i++)
	{
		ptr=(node*)malloc(sizeof(node));
		printf("\n Enter Node Number  %d:\t",i++);

		scanf("%d",&ptr->data);
		temp->next=ptr;
		ptr->prev=temp;
		temp=ptr;
	}
	temp->next=NULL;
	do
	{
		;
		printf("\n------MENU------\n");
		printf("\n 1-INSERTION \n 2-DELETION \n 3-TRAVERSE\n 4-EXIT \n");
		printf("\n-----------------\n");
		printf("\nENTER YOUR CHOICE: \t");
		scanf("%d",&j);
		printf("\n-----------------\n");
		switch(j)
		{
			case 1:
			printf("\nENTER THE NUMBER TO BE INSERTED:\t");
			scanf("%d",&n);
			printf("\n-----------------\n");
			printf("\n ENTER 1 TO INSERT AT THE BEGINING \n");
			printf("\n ENTER 2 TO INSERT AT THE END \n");
			printf("\n ENTER 3 TO INSERT AT A SPECIFIED LOCATION \n");
			printf("\n-----------------\n");
			printf("Enter The Number:\t");
			scanf("%d",&c);
			printf("\n-----------------\n");
			switch(c)
			{
				case 1:
					insbeg(&start,n);
					break;
				case 2:
					insend(&start,n);
					break;
				case 3:
					insafter(start,n);
					break;
				default:
					printf("\n INVALID CHOICE. \n");
			}
			break;
			case 2:
				printf("\n ENTER THE NUMBER TO BE DELETED:\t");
				scanf("%d",&n);
				del(&start,n);
				break;
			case 3:
				traverse(start); // start is same as HEAD
				break;
			case 4:
				exit(0);
			default:
				printf("\n INVALID INPUT \n");
		}
    }while(1);
return 0;
}
