#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 2

int stack[MAX_SIZE],top=-1;

intisfull()
{    // return 1 if stack is full else 0
    if(top==MAX_SIZE-1)
        return 1;
    else
        return 0;
}

intisempty()
{   //returns 1 if stack is full else 0
    if(top==-1)
        return 1;
    else
        return 0;
}

intpeek()
{   //returns the element at the top of the stack
    return stack[top];
}

void push(int e)
{  		  //inserts an element in the stack
    if(!isfull())
	{
        stack[++top]=e;
printf("\n%d is successfully inserted",e);
	}
	else
	{
		printf("\nElement cannot be inserted.\n");
		printf("STACK OVERFLOW");
	}
}


void pop()
{  	 //deletes an element from the stack
	int d;
	if(isempty()!=1)
	{
		d=stack[top--];
		printf("\n%d is successfully deleted",d);
	}
	else
	{
printf("\nSTACK UNDERFLOW");
	}
}

void main()
{
	int choice,e;
	do{
printf("\n--------------------------------------------\n");
		printf("\nEnter your choice:\n 1.PEEK\n 2.PUSH\n 3.POP\n 4.EXIT\n");
		printf("--------------------------------------------\n");
		scanf("%d",&choice);
		
switch(choice)
		{
			case 1:printf("\nElement at the top of stack is : %d",peek()
                  );
                    break;
			case 2:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&e);
				  push(e);	//call push function
					break;
			case 3:
					pop(); 	//call pop function
					break;
			case 4:
					exit(0);
			default:
					printf("\nINVALID CHOICE\n");
					break;
		}
	}while(1);
}
