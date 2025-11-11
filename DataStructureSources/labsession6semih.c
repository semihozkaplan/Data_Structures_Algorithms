/*
* Name: Semih Özkaplan
* Student No: 201504013
* Date: 11.11.2022
* Lab Session 6
*/

// A Stack based C program to find next
// greater element for all array elements.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100

// stack structure
struct stack {
	int top;
	int items[STACKSIZE];
};

// Stack Functions to be used by printNGE()
void push(struct stack* ps, int x)
{
	if (ps->top == STACKSIZE - 1) {
		printf("Error: stack overflown");
		getchar();
		exit(0);
	}
	else {
		ps->top += 1;
		int top = ps->top;
		ps->items[top] = x;
	}
}

bool isEmpty(struct stack* ps)
{
	return (ps->top == -1) ? true : false;
}

int pop(struct stack* ps)
{
	int temp;
	if (ps->top == -1) {
		printf("Error: stack underflow n");
		getchar();
		exit(0);
	}
	else {
		int top = ps->top;
		temp = ps->items[top];
		ps->top -= 1;
		return temp;
	}
}


int main()
{

	int arr[] = { 0,1,2,3,4 };

	struct stack s;
	s.top = -1;

	push(&s, arr[4]);
	push(&s, arr[3]);
	push(&s, arr[2]);
	push(&s, arr[1]);
	push(&s, arr[0]);
	
	for (int i = 0; i < 5; i++)
	{

		printf("The array data: %d\n", s.items[i]);

	}

	printf("\n");

	struct stack s2;
	s2.top = -1;

	int item;

	for (int i = 0; i < 5; i++)
	{

		item = pop(&s);
		push(&s2, item);

	}

	for (int i = 0; i < 5; i++)
	{

		printf("The array data: %d\n", s2.items[i]);

	}

	return 0;
}
