#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node* next;

} Node;

void prntList(Node* head);
Node* newNode(int data);
void push(Node** head_ref, int data);
void removeDuplicate(Node* start); // Unsorted LinkedList
void removeDuplicateS(Node* start); // Sorted LinkedList
Node* sortedIntersectDummy(Node* a, Node* b);


int main(void) {

	Node* head;

	head = newNode(12);
	head->next = newNode(13);
	head->next->next = newNode(13);
	head->next->next->next = newNode(15);

	prntList(head);
	printf("\n");

	removeDuplicate(head);

	prntList(head);
	printf("\n");


	return 0;
}	

Node* newNode(int data) {

	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;

}

void push(Node** head_ref, int data) {

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;

}

void removeDuplicate(Node* start) {  // Unsorted LinkedList

	Node* ptr1, *ptr2, *dup;
	ptr1 = start;

	while (ptr1 != NULL && ptr1->next != NULL)
	{

		ptr2 = ptr1;

		while (ptr2->next !=NULL)
		{

			if (ptr1->data == ptr2->next->data)
			{

				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(dup);

			}

			else
			{
				ptr2 = ptr2->next;
			}

		}

		ptr1 = ptr1->next;

	}

}

void removeDuplicateS(Node* start) { // Sorted LinkedList

	Node* current = start;

	Node* next_next;

	if (current == NULL)
		return;

	while (current->next != NULL) 
	{

		if (current->data == current->next->data)
		{

			next_next = current->next->next;
			free(current->next);
			current->next = next_next;
				
		}

		else
		{

			current = current->next;

		}

	}

}

Node* sortedIntersectDummy(Node* a, Node* b) {

	Node* dummy;
	Node* tail = &dummy;
	dummy.next = NULL;

}

void prntList(Node* head) {
	
	printf("The Data List -> ");

	while (head != NULL) {
			
		printf("%d, ", head->data);
		head = head->next;

	}

}
