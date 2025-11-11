/*
* Semih Özkaplan
* Student No: 201504013
* Lab Session 7
* Date: 02/12/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// Queue Array Implementation
struct Queue {

	int front, rear, size;
	unsigned capacity;
	int* array;

};

// Queue Array Implementation
struct Queue* createQueue(unsigned capacity) {

	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

	queue->capacity = capacity;
	queue->front = queue->size = 0;

	queue->rear = capacity - 1;
	queue->array = (int*)malloc(queue->capacity * sizeof(int));

	return queue;

}

int isFull(struct Queue* queue) {

	return (queue->size == queue->capacity);

}

int isEmpty(struct Queue* queue) {

	return (queue->size == 0);

}

void enqueue(struct Queue* queue, int item) {

	if (isFull(queue))
		return;

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;

}

int dequeue(struct Queue* queue) {

	if (isEmpty(queue))
		return INT_MIN;

	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;

	return item;

}

int front(struct Queue* queue) {

	if (isEmpty(queue))
		return INT_MIN;

	return queue->array[queue->front];

}

int rear(struct Queue* queue) {

	if (isEmpty(queue))
		return INT_MIN;

	return queue->array[queue->rear];

}

int main(void) {

	struct Queue* queue = createQueue(15);
	struct Queue* queue2 = createQueue(15);
	struct Queue* queue3 = createQueue(15);

	int array[15];

	for (int i = 0; i < 15; i++)
	{

		array[i] = rand() % 100;
		printf("%d\n", array[i]);
		
	}

	for (int i = 0; i < 15; i++)
	{
		
		enqueue(queue, array[i]);
		
	}

	for (int i = 0; i < 15; i++)
	{

		if (queue->array[i] < 50) {

			enqueue(queue2, queue->array[i]);
			dequeue(queue, queue->array[i]);

		}

		else if(queue->array[i] >= 50)
		{
			enqueue(queue3, queue->array[i]);
			dequeue(queue, queue->array[i]);
		}


	}

	for (int i = 0; i < queue2->rear + 1; i++)
	{

		printf("Queue 2 -> %d\n", dequeue(queue2));

	}

	for (int i = 0; i < queue3->rear + 1; i++)
	{
		printf("Queue 3 -> %d\n", dequeue(queue3));
	}

	return 0;
}