#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {

	int data;
	struct Node* next;

};

void prntDatas(struct Node* a);
bool search(struct Node* b, int data);
int searchRcv(struct Node* c, int x);
void push(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void append(struct Node** head_ref, int new_data);

int main(void) {

	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	prntDatas(head);

	push(&head, 12);
	insertAfter(second, 200);
	append(&head, 400);


	prntDatas(head); //After push and insertAfter and add last node


	
	//int isFound = searchRcv(head, 15);

	//if (isFound == 1) {

	//	printf("Found it");

	//}

	//else
	//{
	//	printf("Nothing");
	//}


	return 0;
}

void prntDatas(struct Node* a) 
{

	while (a != NULL) 
	{

		printf("The Data: %d\n", a->data);
		a = a->next;


	}

}

bool search(struct Node* b, int data) 
{

	struct Node* current = b;

	while (current != NULL)
	{
		if (current->data == data) {

			return true;
			current = current->next;
		}

	}

	return false;
	
}

int searchRcv(struct Node *c, int x) 
{

	if (c == NULL) {

		return 0;

	}

	if (c->data == x) {

		return 1;

	}

	return searchRcv(c->next, x);

}

void push(struct Node** head_ref, int new_data) 
{

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;

}

void insertAfter(struct Node* prev_node, int new_data) 
{

	if (prev_node == NULL) 
	{
		return; // Ýf it is empty, do not anything
	}

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = prev_node->next;

	prev_node->next = new_node;

}

void append(struct Node** head_ref, int new_data) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *head_ref;

	new_node->data = new_data;

	new_node->next = NULL; // Sonuncu node olacaðý için null döndürdük.

	// Eðer node yok ise yeni oluþtur ve head olarak ata.
	if(*head_ref == NULL){
	
		*head_ref = new_node;
		return;

	}

	// Else son node u yani null olan node u bulana kadar gez.
	while (last->next != NULL) {

		last = last->next;

	}

	// son olan node u deðiþtir ve oluþturduðumuz new node a ata
	last->next = new_node;
	return;

}