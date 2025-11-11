#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct DoubleStack {

	int topA;
	int topB;
	unsigned capacityA;
	unsigned capacityB;
	int* arrayA;
	int* arrayB;

};

struct DoubleStack* createStackA(unsigned capacity) {

	struct DoubleStack* stack = (struct DoubleStack*)malloc(sizeof(struct DoubleStack));
	stack->capacityA = capacity;
	stack->topA = -1;
	stack->arrayA = (int*)malloc(stack->capacityA * sizeof(int));
	return stack;

}

struct DoubleStack* createStackB(unsigned capacity) {

	struct DoubleStack* stack = (struct DoubleStack*)malloc(sizeof(struct DoubleStack));
	stack->capacityB = capacity;
	stack->topB = -1;
	stack->arrayB = (int*)malloc(stack->capacityB * sizeof(int));
	return stack;

}

int isFullA(struct DoubleStack* stack) {

	if (stack->topA == stack->capacityA - 1)
	{
		return 1;
	}

}

int isFullB(struct DoubleStack* stack) {

	return stack->topB == stack->capacityB - 1;

}

int isEmptyA(struct DoubleStack* stack) {

	return stack->topA == -1;

}

int isEmptyB(struct DoubleStack* stack) {

	return stack->topB == -1;

}

void pushA(struct DoubleStack* stack, int item) {
		
	stack->arrayA[++stack->topA] = item;
	printf("%d pushed to stack A\n", item);

}

void pushB(struct DoubleStack* stack, int item) {
		
	stack->arrayB[++stack->topB] = item;
	printf("%d pushed to stack B\n", item);

}

int popA(struct DoubleStack* stack) {

	if (isEmptyA(stack))
		return INT_MIN;

	return stack->arrayA[stack->topA--];

}

int popB(struct DoubleStack* stack) {

	if (isEmptyB(stack))
		return INT_MIN;

	return stack->arrayB[stack->topB--];

}

int peekA(struct DoubleStack* stack) {

	if (isEmptyA)
		return INT_MIN;
	return stack->arrayA[stack->topA];

}

int peekB(struct DoubleStack* stack) {

	if (isEmptyB)
		return INT_MIN;
	return stack->arrayB[stack->topB];

}

int main(void)
{

	int size;

	printf("Please enter the size of Stack -> ");
	scanf_s("%d", &size);

	struct DoubleStack* stackA = createStackA(size);
	struct DoubleStack* stackB = createStackB(size);
	int data;

	
	for (int i = 0; i < size; i++)
	{

		printf("Please enter the data that you want to push -> ");
		scanf_s("%d", &data);

		pushA(stackA, data);

	}


	printf("There is no empty anymore in stack A\n");
	printf("It will continue to push stack B\n\n");

	for (int i = 0; i < size; i++)
	{
		printf("Please enter the data that you want to push -> ");
		scanf_s("%d", &data);

		pushB(stackB, data);
	}


	return 0;
}
