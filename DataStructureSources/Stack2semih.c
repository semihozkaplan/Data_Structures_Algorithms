#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#define STACKSIZE 100
#define bool int

/*
* Name Surname: Semih Özkaplan  
* Course: Data Structure and Algorithms
* Date: 08.12.2022
* Student Number: 201504013
*/

// Stack Array Implementation for pushing integer datas
struct Stack {

	int top;
	int datas[STACKSIZE];

};

// Stack Linked List Implementation
struct StackN {

	char data;
	struct StackN* next;

};

// Stack Array Implementation for pushing char datas 
struct StackC{

	int top;
	unsigned capacity;
	char* arrayC;

};


int isEmpty(struct Stack* stack);  // This function check the stack if it is empty
int isEmptyC(struct StackC* stack);  // This function check the stack if it is full
void push(struct Stack* stack, int data); // Pushing an element to the stack (Array Implementation)
void pushN(struct StackN** top_ref, int new_data); // Pushing an element to the stack (Linkedlist Implementation)
void pushC(struct StackC* stack, char c); // Pushing an element char to the stack (Array Implementation)
int pop(struct Stack* stack); // Poping an element from the stack (Array Implementation)
int popN(struct StackN** top_ref); // Poping an element from the stack (Linkedlist Implementation)
char popC(struct StackC* stack); // Poping an element char from the stack (Linkedlist Implementation)
void findingNSE(int arr[], int n); // This function finds the next smaller element of an array
int isMatch(char character1, char character2); // This function checks the characters if they match as bracklets
int balancedOrNot(char sequence[]); // This function checks if sequence is balanced or not
char peekC(struct StackC* stack); // This function peek an element char from the stack
struct StackC* createStackC(unsigned capacity); // This function creates the stack
int isOpr(char c); // This function checks if char is operand or not 
int precedence(char c); // This functions precedence the operator.
int infixToPostfix(char* sequence); // This function converts the infix sequence to the postfix sequence
void towerOfHanoi(int n, struct StackN* from_rod, struct StackN* to_rod, struct StackN* aux_rod); // Tower of Hanoi problem using stack


void question1(void); // Next smaller element Problem
void question2(void); // Balanced or Not Problem
void question3(void); // Infix to Postfix Problem
void question4(void); // Tower of Hanoi Problem using stack
void question6(void); // Inverse the string Problem using stack
void question7(void); // Driver Program

int main(void) {

	question7();
	
	return 0;
	
}


int isEmpty(struct Stack* stack) {

	// Ternary If Statement
	return (stack->top == -1) ? true : false;

}

int isEmptyC(struct StackC* stack)
{
	return stack->top == -1;
}


void push(struct Stack* stack, int data){

	if (stack->top == STACKSIZE - 1) {

		printf("Stack has Overflown !!!");
		exit(0);

	}

	else {

		stack->top += 1;
		int top = stack->top;
		stack->datas[top] = data;

	}

}

void pushN(struct StackN** top_ref, int new_data) {
	
	struct StackN* new_node = (struct StackN*)malloc(sizeof(struct StackN));

	if (new_node == NULL) {

		printf("Stack has OverFlown !!!");
		exit(0);

	}

	new_node->data = new_data;

	new_node->next = (*top_ref);

	(*top_ref) = new_node;

}

void pushC(struct StackC* stack, char c)
{

	if ((stack->top) == (stack->capacity - 1))
	{
		printf("Stack is Full !!");
		return;
	}

	stack->arrayC[++stack->top] = c;

}

int pop(struct Stack* stack) {

	int tempNum;

	if (stack->top == -1) {

		printf("Stack has Underflown !!!");
		exit(0);

	}

	else {

		int top = stack->top;
		tempNum = stack->datas[top];
		stack->top -= 1;
		return tempNum;

	}

}

int popN(struct StackN** top_ref) {

	char temp;
	struct StackN* top;

	if ((* top_ref) == NULL) {

		printf("Stack has overflown !!!");
		exit(0);

	}

	else {

		top = (* top_ref);
		temp = top->data;
		(* top_ref) = top->next;
		free(top);

		return temp;
	
	}


}

char popC(struct StackC* stack)
{
	if (isEmpty(stack))
		return '?';

	else
		return stack->arrayC[stack->top--];

}

void findingNSE(int array[], int size) {

	int index = 0;

	struct Stack stack;
	stack.top = -1;

	int number;
	int	nextNum;

	// Pushing the first element to the stack
	push(&stack, array[0]);

	// Iterate for next elements
	for (index = 1; index < size; index++) {
		
		nextNum = array[index];

		if (isEmpty(&stack) == false) {

			// If stack is not empty then pop() it. And assign it as a variable.
			number = pop(&stack);

			// If the number is greater than next element, then print the number first
			// and then print the next smaller element
			while (number > nextNum) {

				printf("NSE %d --> %d\n", number, nextNum);

				if (isEmpty(&stack) == true)
					break;

				number = pop(&stack);

			}

			// If the number is smaller than next number then, push it to the stack
			if (number < nextNum)
				push(&stack, number);

		}

		// Push the next number to the stack to find the next smaller number of the next number
		push(&stack, nextNum);
	}

	// After the loop, for the remaininn elements, print the number and next element as -1
	while (isEmpty(&stack) == false) {

		number = pop(&stack);
		nextNum = -1;
		printf("NSE %d --> %d\n", number, nextNum);

	}


}

int isMatch(char c1, char c2) {

	if (c1 == '(' && c2 == ')')
		return 1;

	else if (c1 == '{' && c2 == '}')
		return 1;

	else if (c1 == '[' && c2 == ']')
		return 1;

	else
		return 0;

}

int balancedOrNot(char sequence[]) {

	int index = 0;

	struct StackN* stack = NULL;
	
	while (sequence[index]) {
		
		if (sequence[index] == '{' || sequence[index] == '(' || sequence[index] == '[')
				pushN(&stack, sequence[index]);

	
		if (sequence[index] == '}' || sequence[index] == ')' || sequence[index] == ']') 
		{

			if (stack == NULL)
				return 0;

			else if (!isMatch(popN(&stack), sequence[index]))
				return 0;

		}

		index++;
	
	}

	// Balanced
	if (stack == NULL)
		return 1;

	// Not Balanced
	else
		return 0;

}

char peekC(struct StackC* stack) {

	return stack->arrayC[stack->top];

}

struct StackC* createStackC(unsigned capacity) {

	struct StackC* stack = (struct StackC*)malloc(sizeof(struct StackC));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->arrayC = (char*)malloc(stack->capacity * sizeof(char));

	return stack;

}


int isOpr(char c)
{

	// Check if it is a letter between a and z, in other words check if it is operand
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return 1;
	}

	else
		return 0;

}

// This function defines the precedence of the operations
// High number means high precedence
int precedence(char c)
{

	switch (c) {

	case '+':
		return 1;
		break;

	case '-':
		return 1;
		break;

	case '*':
		return 2;
		break;

	case '/':
		return 2;
		break;

	case '^':
		return 3;
	}

	return -1;

}

// The function that convert the infix sequences into postfix sequences
int infixToPostfix(char* sequence)
{

	int index, index2;
	int sizeSeq = strlen(sequence) / sizeof(sequence[0]); // Size of the stack

	// Creating a stack
	struct StackC* stack = createStackC(strlen(sequence));

	//Check the stack, if it is empty
	if (!stack) 
		return -1;

	for (index = 0, index2 = -1; index < sizeSeq; ++index) {

		// Check the sequence using index, if the char of the sequence is operand
		if (isOpr(sequence[index]))
			sequence[++index2] = sequence[index];

		// If it is left bracklet then push it to the stack
		else if (sequence[index] == '(')
			pushC(stack, sequence[index]);

		// Check if it is right bracklet
		else if (sequence[index] == ')') {
			
			// Enter the loop until the stack is not empty and it is left bracket, then assign it as char of the sequence and pop it.
			while (!isEmptyC(stack) && peekC(stack) != '(')
				sequence[++index2] = popC(stack);
			
			// If it is not empty and top of the stack is left bracklet then return -1
			if (!isEmptyC(stack) && peekC(stack) != '(')
				return -1; // invalid expression
			
			// Else pop it.
			else
				popC(stack);
		}

		// If it is operator then enter the else.
		else 
		{
			// Enter the loop if it is not empty and operand's precedence is lesser than the stack's top of the operand
			while (!isEmptyC(stack) && precedence(sequence[index]) <= precedence(peekC(stack)))
				sequence[++index2] = popC(stack); // Pop it according to precedence and assign it as char of sequence

			// Then push it to the stack
			pushC(stack, sequence[index]);
		}
	}

	// Pop the operators from stack
	while (!isEmptyC(stack))
		sequence[++index2] = popC(stack);

	sequence[++index2] = '\0';
	
	printf("%s", sequence);
}


void towerOfHanoi(int n, struct StackN* from_rod, struct StackN* to_rod, struct StackN* aux_rod)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", from_rod->data, to_rod->data);
		return;
	}

	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

	printf("\n Move disk %d from rod %c to rod %c", n, from_rod->data, to_rod->data);

	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}


void question1(void) {

	int array[] = { 12, 5, 42, 7 };

	int sizeArr = sizeof(array) / sizeof(array[0]);
	findingNSE(array, sizeArr);

}

void question2(void) {

	char sequence[100] = "[(a+b)/c]+{2x^2}+{[(a+c)/(b+c)](22*b)}";
	printf("The Sequence ->> %s\n\n", sequence);

	if (balancedOrNot(sequence) == 1)
		printf("Sequence is Balanced \n");

	else
		printf("Sequence is NOT Balanced !!! \n");


}

void question3(void) {

	/*Why Postfix representation of the mathematical expression is useful ?
	* Because
	* 1. The sequence can be represented without parenthesis and bracklets
	* 2. It is easier to evaluate the formula
	* 3. It is easy to understand the order of the operations that are applied.
	* 4. It has not the operator precedence.
	* 5. It can be represented on computers using stacks.
	*/

	char sequence[] = "(x-y)*(z/t)^3";

	printf("The infix ->> %s\n", sequence);
	printf("Postfix ->> ");
	infixToPostfix(sequence);

}

void question4(void) {

	/*
	* Tower of Hanoi is a problem that includes 3 rods and multiple disks
	* In this problem, all rods are on one rode and the purpose is moving these disks to other rod.
	* The important points are a disk cannot be placed on top of a smaller disk and
	* no disk can be placed on top of the smaller disk.
	*/

	struct StackN* pole1;
	struct StackN* pole2;
	struct StackN* pole3;

	pushN(&pole1, 'A');
	pushN(&pole2, 'C');
	pushN(&pole3, 'B');

	int n;

	printf("Please enter the disk number ->> ");
	scanf_s("%d", &n);

	towerOfHanoi(n, pole1, pole2, pole3);

}

void question6(void) {

	char name[20];

	printf("Please enter your name and surname: ");
	getchar();
	gets(name);

	struct StackC* nameSurname = createStackC(strlen(name));

	for (int i = 0; i < strlen(name); i++)
	{
		pushC(nameSurname, name[i]);
	}

	for (int i = 0; i < strlen(name); i++)
	{
		printf("%c", popC(nameSurname));
	}
	
}

void question7(void) {

	char isOpen;

	printf("Do you want to open the Homework ? (y/n) ->> ");
	scanf_s("%c", &isOpen);

	while (isOpen == 'y')
	{
		
		printf("***Welcome to HOMEWORK 2***\n");
		printf("1.Question\n");
		printf("2.Question\n");
		printf("3.Question\n");
		printf("4.Question\n");
		printf("5.Question\n");
		printf("6.Question\n");

		int number;

		printf("Please enter the question number that you want to check ->> ");
		scanf_s(" %d", &number);

		printf("\n");

		switch (number) {

		case 1:
			question1();
			printf("\n\n");
			break;

		case 2:
			question2();
			printf("\n\n");
			break;

		case 3:
			question3();
			printf("\n\n");
			break;

		case 4:
			question4();
			printf("\n\n");
			break;

		case 5:
			printf("Teacher sorry I tried but could not do this question :(");
			printf("\n\n");
			break;

		case 6:
			question6();
			printf("\n\n");
			break;

		default:
			printf("Please enter a valid number !!!");

		}

		printf("Do you want to open the Homework again ? (y/n) ->> ");
		scanf_s(" %c", &isOpen);

	}

}
