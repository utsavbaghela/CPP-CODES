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
void sortstack()
{

}
int main(void)
{
	s.top=-1;
	push(5);
	push(4);
	push(1);
	push(3);
	push(2);
	printf("ORIGINAL STACK : ");
	print();
	sortstack();

	printf("\nSORTED STACK   : ");
	print();



}
