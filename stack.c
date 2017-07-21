#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],TOP=-1;

int isFull(){
	if(top==MAX_SIZE)
	  return 1;
	  else
	  return -1;
}

int isEmpty(){
	if(top==-1)
	return 1;
	else 
	return -1;
}

int peek(){
	return stacK[top];
}

void push(int e){
	if(!isFull())
	{  top++;
		stack[top]=e;
		printf('Element e is successfully inserted \n');
	}
	else
	printf('Stack Overflow');
}

void pop(){
	int d;
	if(!isEmpty())
	{   d=stack[top];
		top--;
		printf("Element %d succesfully deleted \n",d);
	}
	else
	printf('stack Underflow \n');
}

int main(){
	int choice ,e;
	do
	{  printf("1.peek\n 2.push \n 3.pop\n 4.exit\n ")
		printf("Enter your choice \n ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: peek();
			        break;
			case 2: push();
                                break;
                        case 3: pop();
                                break;
                        case 4: exit;
                                break;
		
	}
}
