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


void printNGE(int arr[], int n)
{

	struct stack s;
	s.top = -1;

	int element, next;
	
	push(&s, arr[0]);

	for (int i = 1; i < n; i++) {
		next = arr[i];

		if (isEmpty(&s) == false) {
			
			element = pop(&s);
			
			while (element < next) {
				printf("n %d --> %d\n", element, next);
				if (isEmpty(&s) == true)
					break;
				element = pop(&s);
			}

			
			if (element > next)
				push(&s, element);
		}	
		push(&s, next);

	}

	while (isEmpty(&s) == false) {
		element = pop(&s);
		next = -1;
		printf("n %d --> %d\n", element, next);
	}

}

/* Driver code */
int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, n);
	getchar();
	return 0;
}
