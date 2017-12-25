/*
 ============================================================================
 Name        : Stack.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int j=0;
int k=0;
struct stack
{
	char stk[20];
	int top ;
};
struct stack s;
void push (int x)
{
	if(s.top>19)
		{
		printf("STACKOVERFLOW");
		exit(0);
		}
	else
	{
		//k++;
		s.top++;
		s.stk[s.top]=x;
	}
}
int pop()
{
	int x;
	//k++;
		x=s.stk[s.top];
		s.top--;

		return x;
}
int stacktop()
{
	if(s.top==-1)
		return -1;
	else
		return s.stk[s.top];

}

int isoperand(char c)
{
	if(c >= '0' && c <= '9')
		return 1;
	else if(c >= 'a' && c <= 'z')
		return 1;
	else if(c >= 'A' && c <= 'Z')
		return 1;
	else
		return 0;
}


int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}


int main()
{
	char exp[40];
	printf("ENTER THE EXPRESSION");
	gets(exp);
	s.top=-1;
	char postfix[40];
	///int n=sizeof(exp);
	int a;

	for(int i=0,j=0;exp[i]!='\0';i++)
	{
		if(isoperand(exp[i]))
		{
			postfix[k++]=exp[i];
			//printf("%s\n",postfix);
		}
		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' )
		{
			/*if(s.top==-1)
				push(exp[i]);
			else
			{
			a= prcd(s.stk[s.top],exp[i]);
			//printf("%s\n",s.stk);

					if(a==0)
						push(exp[i]);
					else*/

			while ((stacktop!=-1) && (Prec(exp[i]) <= Prec(s.stk[s.top])))
			postfix[k++]=pop();

			push(exp[i]);


		}
		printf("INFIX   : %c\n",exp[i]);
		printf("STACK   : %s\n",s.stk);
		printf("POSTFIX : %s\n\n",postfix);

	}
	//printf("%s",postfix);
	//printf("%d\n",s.top);
	while (s.top != -1)
	    postfix[k++] = pop();

	    printf( "FINAL ANSWER : %s\n", postfix );

}
