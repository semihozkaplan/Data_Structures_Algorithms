#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A linked list node
struct Node
{
	int data;
	char name[20];
	char namedata;
	struct Node* next;

};

struct NodeC
{
	int data;
	int time;
	char name[20];
	char id[20];
	struct NodeC* next;
};

void print(struct Node* n) {     // a function for printing values
	while (n != NULL) {
		printf("%d", n->data);
		n = n->next;
	}
}

void printC(struct Node* n) {     //this is a function for print strings
	while (n != NULL) {
		printf("%c", n->namedata);
		n = n->next;
	}
}
// Given a reference (pointer to pointer) to
// the head of a list and an int, inserts a
// new node on the front of the list.
void push(struct Node** head_ref, int new_data)      //function for insert data item a the beggining
{
	// 1. Allocate node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	// 2. Put in the data
	new_node->data = new_data;

	// 3. Make next of new node as head
	new_node->next = (*head_ref);

	// 4. move the head to point to
	// the new node
	(*head_ref) = new_node;
}

void pushC(struct NodeC** head_ref,				//function for isnert character item at the beggining
	char new_data)
{
	// 1. Allocate node
	struct NodeC* new_node =
		(struct NodeC*)malloc(sizeof(struct NodeC));

	// 2. Put in the data
	new_node->data = new_data;

	// 3. Make next of new node as head
	new_node->next = (*head_ref);

	// 4. move the head to point to
	// the new node
	(*head_ref) = new_node;
}

// Given a node prev_node, insert a
//// new node after the given prev_node
void insertAfter(struct Node* prev_node,          //function for inserting a data after given node
	int new_data)
{
	// 1. Check if the given prev_node
	// is NULL
	if (prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;

	}
	// 2. Allocate new node
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	// 3. Put in the data
	new_node->data = new_data;

	// 4. Make next of new node as next
	// of prev_node
	new_node->next = prev_node->next;

	// 5. Move the next of prev_node
	// as new_node
	prev_node->next = new_node;
}

void insertAfterC(struct NodeC* prev_node,				 //function for inserting a character after given node
	char new_data)
{
	// 1. Check if the given prev_node
	// is NULL
	if (prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;


	}

	// 2. Allocate new node
	struct NodeC* new_node =
		(struct NodeC*)malloc(sizeof(struct NodeC));

	// 3. Put in the data
	new_node->data = new_data;

	// 4. Make next of new node as next
	// of prev_node
	new_node->next = prev_node->next;

	// 5. Move the next of prev_node
	// as new_node
	prev_node->next = new_node;
}

// Given a reference (pointer to pointer) to
// the head of a list and an int, appends a
// new node at the end
void append(struct Node** head_ref,   //function for inserting a data at the end of the node
	int new_data)
{
	// 1. Allocate node
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	// Used in step 5
	struct Node* last = *head_ref;


	// 2. Put in the data
	new_node->data = new_data;

	// 3. This new node is going to be the
	// last node, so make next of it as NULL
	new_node->next = NULL;

	// 4. If the Linked List is empty, then make
	// the new node as head
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	// 5. Else traverse till the last node
	while (last->next != NULL) {
		last = last->next;
	}
	// 6. Change the next of last node
	last->next = new_node;
	return;
}

void appendC(struct Node** head_ref, char new_data)
{

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = (*head_ref); 

	new_node->namedata = new_data;

	new_node->next = NULL;

	if ((*head_ref) == NULL)
	{

		(*head_ref) = new_node;
		return;

	}

	while (last->next != NULL)
	{

		last = last->next;

	}

	last->next = new_node;

}

void appendN(struct NodeC** head_ref, char new_data[])     //function for inserting string(names) at the end of the node 
{
	// 1. Allocate node
	struct NodeC* new_node =
		(struct Nodec*)malloc(sizeof(struct NodeC));

	// Used in step 5
	struct NodeC* last = *head_ref;

	// 2. Put in the data
	strcpy(new_node->name, new_data);

	// 3. This new node is going to be the
	// last node, so make next of it as NULL
	new_node->next = NULL;

	// 4. If the Linked List is empty, then make
	// the new node as head
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	// 5. Else traverse till the last node
	while (last->next != NULL) {
		last = last->next;
	}
	// 6. Change the next of last node
	last->next = new_node;
	return;
}

void deleteN(struct Node** head, int position)		//function for delete from a node
{
	struct	Node* temp;
	struct	Node* prev;
	temp = *head;
	prev = *head;
	for (int i = 0; i < position; i++) {
		if (i == 0 && position == 1) {
			*head = (*head)->next;
			free(temp);
		}
		else {


			if (i == position - 1 && temp) {
				prev->next = temp->next;
				free(temp);
			}
			else {
				prev = temp;

				// Position was greater than
				// number of nodes in the list
				if (prev == NULL)
					break;
				temp = temp->next;
			}
		}
	}
}

void pushName(struct NodeC** head_ref, char new_data[]) {  //function for pushing name strings at the beggining of the node

	struct NodeC* new_node = NULL;
	strcpy(new_node->name, new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;

	while ((*head_ref) != NULL) {
		printf("%s\n", (*head_ref)->name);
		(*head_ref) = (*head_ref)->next;

	}
}
void prn(struct Node* n) {			//function for print names

	while (n != NULL) {
		printf("%s\n", n->name);
		n = n->next;
	}
}

void question6(void) {

	struct Node* temp = NULL;

	appendC(&temp, 'T');
	appendC(&temp, 'u');
	appendC(&temp, 'a');
	appendC(&temp, 'n');
	appendC(&temp, 'a');
	appendC(&temp, ' ');
	appendC(&temp, 'K');
	appendC(&temp, 'a');
	appendC(&temp, 'r');
	appendC(&temp, 'a');

	printC(temp);
	printf("\n");

	deleteN(&temp, 6);
	deleteN(&temp, 5);
	deleteN(&temp, 4);
	deleteN(&temp, 3);
	deleteN(&temp, 2);
	deleteN(&temp, 1);
	appendC(&temp, ' ');
	appendC(&temp, 'T');
	appendC(&temp, 'u');
	appendC(&temp, 'a');
	appendC(&temp, 'n');
	appendC(&temp, 'a');

	printC(temp);
	printf("\n");


	deleteN(&temp, 5);
	deleteN(&temp, 4);
	deleteN(&temp, 3);
	deleteN(&temp, 2);
	deleteN(&temp, 1);

	struct Node* hSecondList = NULL;

	appendC(&hSecondList, ' ');
	appendC(&hSecondList, 'K');
	appendC(&hSecondList, 'a');
	appendC(&hSecondList, 'r');
	appendC(&hSecondList, 'a');

	appendC(&temp, hSecondList->namedata);
	appendC(&temp, hSecondList->next->namedata);
	appendC(&temp, hSecondList->next->next->namedata);
	appendC(&temp, hSecondList->next->next->next->namedata);
	appendC(&temp, hSecondList->next->next->next->next->namedata);
	

	printC(temp);
	printf("\n");

}

int main(void) {
	struct Node* head = NULL;
	question6();
	return 0;
}
