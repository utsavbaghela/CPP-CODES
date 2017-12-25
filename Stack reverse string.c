//============================================================================
// Name        : practice.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <string.h>
int a[50];
int top=-1;
void reverse(char c[],int length);
void push(char x);


void push(char x)
{
	top=top+1;
	a[top]=x;
}
void pop()
{
	top--;
}
void reverse(char c[],int length)//utsav//length =5;
{
	for(int i=0;i<=length-1;i++)
	{
		push(c[i]);
	}
	for(int i=0;i<=length-1;i++)
	{
		c[i]=a[top];
		pop();

	}

}
int main()
{
	char c[50];
	printf("Enter a string : ");
	gets(c);
	reverse(c,strlen(c));
	printf("REVERSE STRING : %s",c);
}
