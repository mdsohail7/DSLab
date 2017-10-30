#include <stdio.h>
#define MAXSIZE 3

int queue[MAXSIZE];
int front=-1,rear=-1;

int isFull()
{
	return (rear==MAXSIZE-1 && front==0) || ( front==rear+1);
}

int isEmpty()
{	//returns 1 if stack is full else -1
		return (rear==-1 && front==-1);
}

void Display()
{	int i=front;
	if(!isEmpty())
    {
		while(i!=rear)
		{
			printf("%d\n",queue[i]);
			i=(i+1)%MAXSIZE;
		}
		printf("%d\t",queue[i]);
	}
	else
    {
		printf("\nQueue is Empty.");
	}
}

void Insert(int d)
{
	if(isFull())
	{
		printf("\nQueue Is Full");
		return;
	}
	else
	{	rear=(rear+1)%MAXSIZE;
		queue[rear]=d;
			if(front==-1)
				front++;
	}
	printf("\nElement :: %d :: Successfully Inserted ",d);
}

void Delete()
{
	int d;
	if(isEmpty())
	{
		printf("\nQueue Is Empty");
		return;
	}
	else
	{
		d=queue[front];
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				front=(front+1)%MAXSIZE;
			}
        printf("\nElement %d is successfully Inserted",d);
	}
}

void main(){
	int choice,e;
	do
	{
        printf("\n--------------MENU-------------");
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("-------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);	//take input in choice variable
		printf("-------------------------------\n");
		switch(choice){
		    case 1:
				printf("\nEnter the Element To Be Inserted: ");
				scanf("%d",&e);
				Insert(e);//call Insert function
				break;
			case 2:
				Delete();   //call Delete function
				break;
			case 3:
				Display();
				break;
			case 4:
				exit(0);      //call exit(0) function or return 0
				break;
			default:
				printf("\nInvalid Choice");     // if the choice is not correct
				break;
		}
	}while(1);
}
