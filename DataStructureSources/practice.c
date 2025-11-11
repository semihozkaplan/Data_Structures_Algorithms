#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {

	int data;
	struct Node* next;

}node;

void prntValuesLinkedList(struct Node* a);

int main(void) {
	
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* tail = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	tail = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = tail;

	tail->data = 4;
	tail->next = NULL;

	prntValuesLinkedList(head);

	return 0;
}

void prntValuesLinkedList(struct Node* a) {

	while (a != NULL) 
	{

		printf("The Data: %d\n", a->data);
		a = a->next;

	}

}
