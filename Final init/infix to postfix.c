#include<stdio.h>
#include<ctype.h> //for isaplha() function

typedef struct conversion
{
	char a[30];
	int top;
}stack;

void push(stack*,char);. // FunctionToPush The Value

char pop(stack*);     // Function To Pop The Value

void convert(char[],char[]);    // Function To Convert Infix to Postfix Expression

int priority(char);   // Function To Check Priority Of The Operator

intmain()
{
	char infix[30],postfix[30];
	printf("\nENTER INFIX EXPRESSION:\n");
	scanf("%s",infix);
	convert(infix,postfix);
	printf("\n\nPOSTFIX EXPRESSION:\n%s",postfix);
	return 0;
}

void convert(char in[],char post[])
{
	char opr;
	stack s1;
	int j=0,i;
	s1.top=-1;
	for(i=0;in[i]!='\0';i++)
	{
		if(isalpha(in[i]))
			post[j++]=in[i];
		if(in[i]=='(')
			push(&s1,in[i]);
		if(in[i]=='+'||in[i]=='-'||in[i]=='/'||in[i]=='*')
		{
			if(s1.top!=-1)
			{
				opr=pop(&s1);
				while(priority(opr)>=priority(in[i]))
				{
					 post[j++]=opr;
					opr=pop(&s1);
				}
				push(&s1,opr);
				push(&s1,in[i]);
			}
			else
				push(&s1,in[i]);
		}
		if(in[i]==')')
		{
			opr=pop(&s1);
			while(opr!='(')
			{
				post[j++]=opr;
				opr=pop(&s1);
			}
		}
	}
	
while(s1.top!=-1)
		post[j++]=pop(&s1);
	post[j]='\0';
 }

intpriority(char c)
{
	 if(c=='$')
		return 3;
	 if(c=='/'||c=='*')
		return 2;
	 if(c=='+'||c=='-')
		return 1;
	 else
		return 0;
}

void push(stack *s,charopr)
{
	s->top++;
	s->a[s->top]=opr;
}


char pop(stack *s)
{
	if (s->top==-1)
	{
		printf("stack is empty\n");
		return 0;
    }
    else
    {
		char data=s->a[s->top--];
		return data;
    }
}
