#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 2

int queue[MAX_SIZE],front=-1,rear=-1;

intisfull()
{  		// return 1 if Queue is full else return 0
	if(rear==MAX_SIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

intisempty()
{  		//returns 1 if Queue is full else 0
	if(front==-1 && rear==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display()
{
	inti;
	printf("\nThe Element of the Queue are :\n");
	for(i=front;i<=rear;i++)
	{
		printf("\n%d",queue[i]);
	}
}

void insert(int d )
{               // function to insert value
	if (!isfull())
	{
		if (isempty())
			front++;
		rear++;
		queue[rear]=d;
		printf("\n%d is successfully inserted\n",d);
	}
	else
	{
		printf("\nElement is full cannot be inserted\n");
	}
}



void  delete ()
{               //function to delete value
	int d;
	if(!isempty())
	{
		d=queue[front];
		if (front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front++;
		}
		printf("\nThe Element Deleted is %d ",d);
	}
	else
	{
		printf("\nThe Queue is Empty");
	}
}


intmain()
{
	int choice,e;
	do{
	printf("\n----------------------------------\n");
printf("\nEnter your choice:\n 1.Display\n 2.Insert\n 3.Delete\n 4.Exit\n");
		printf("\n----------------------------------\n");
		scanf("%d",&choice);
		switch(choice)
		{
case 1:             // call display function and display value
					if(!isempty())
						display();
					else
						printf("\n Queue Is Empty:");
					break;
			case 2:
printf("\n	Enter The Element To Be Inserted: ");
					scanf("%d",&e);
					insert(e); 	 //call insert function
					break;
			case 3:
					delete();   //call delete function
					break;
			case 4:
					exit(0);
					break;
			default:
					printf("INVALID CHOICE");
					break;
		}
	}while(1);
	return 0;
}
