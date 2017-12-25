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
//int temp;
struct stack
{
	int top;
	int top1;
	int stk[];
}s;
void push(int x)
{
	s.top++;
	s.stk[s.top]=x;
}
int pop()
{
	int x=s.stk[s.top];
	s.top--;
	return x;
}
void print()
{
	s.top1=s.top;
    printf("\n");
    while (s.top1 != -1)
    {
        printf(" %d ", s.stk[s.top1]);

        s.top1--;
    }
    printf("\n");
}
void reverse()
{
	//printf("%d\n",s.top);
	if(s.top!=-1)
	{
		int temp=pop();//1
		//printf("%d ",s.top);
		reverse();
		insert(temp);
	}
}

int insert(int item)
{

	if(s.top==-1)
		push(item);
	else
	{
		int temp=pop();
		insert(item);

		push(temp);
	}
}

int main()
{
	s.top=-1;
	push(1);
	push(2);
	push(3);
	push(4);
	push(8);

	printf("ORIGINAL STACK : ");
	print();
	reverse();
	printf("\nREVERSED STACK : ");
	print();
	return 0;


}
