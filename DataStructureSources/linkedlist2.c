#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A linked list node
struct Node
{
	int data;
	char name[20];
	char spellName;
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

void printC(struct NodeC* n) {     //this is a function for print strings
	while (n != NULL) {
		printf("%c", n->data);
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
// new node after the given prev_node
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
void append(struct Node** head_ref, int new_data)
{
	// 1. Allocate node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

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

void appendCTime(struct NodeC** head_ref, int new_data)
{
	// 1. Allocate node
	struct NodeC* new_node = (struct NodeC*)malloc(sizeof(struct NodeC));

	// Used in step 5
	struct NodeC* last = *head_ref;


	// 2. Put in the data
	new_node->time = new_data;

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

void appendC(struct NodeC** head_ref,			//function for inserting a data at the end of the node
	char new_data)
{
	// 1. Allocate node
	struct NodeC* new_node =
		(struct Nodec*)malloc(sizeof(struct NodeC));

	// Used in step 5
	struct NodeC* last = *head_ref;


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

void deleteN(struct NodeC** head, int position)
{
	struct	NodeC* temp;
	struct	NodeC* prev;
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

void pushName(struct NodeC** head_ref, char new_data) {  //function for pushing name strings at the beggining of the node

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

void prnTime(struct Node* n) {		//function for print time on the screen
	while (n != NULL) {
		printf(" %d.00\n", n->data);
		n = n->next;
	}
}

void prnTimeC(struct NodeC* n) {		//function for print time on the screen
	while (n != NULL) {
		printf("%d.00\n", n->time);
		n = n->next;
	}
}

int timeSearch(struct NodeC* t, int time) {   // function for searching time to detect if it's chosen from someone else
	struct NodeC* a = t;

	while (a != NULL) {
		if (a->data == time) {
			return 1;
		}

		a = a->next;
	}
	return 0;

}

void printBooks(struct NodeC* n, struct NodeC* t) {		 // function for printing patient's books to see everyone on the screen
	while (n != NULL && t != NULL) {
		printf("%s  %d.00 \n", n->name, t->time);
		printf("\n");
		n = n->next;
		t = t->next;

	}
}


void question4() {

	struct Node* head = NULL;

	int isAvailable = 1;         //variable for timeSearch function,
	char name[20];
	char id[20];
	char isShow;
	int time;
	struct NodeC* hTime = NULL;
	struct NodeC* AvailableTime = NULL;
	struct NodeC* hName = NULL;
	struct NodeC* hId = NULL;

	struct NodeC* temp = hTime;
	appendCTime(&AvailableTime, 9);
	appendCTime(&AvailableTime, 12);
	appendCTime(&AvailableTime, 15);


	printf("Do you want to see the screen? (y/n)\n");
	scanf(" %c", &isShow);

	while (isShow == 'y') {
		printf("the available time is: \n");

		prnTimeC(AvailableTime);

		printf("please enter your time selection: (write without .00 please)\n ");
		scanf("%d", &time);

		if (time != 9 && time != 12 && time != 15) {
			printf("please choose a valid time.\n");
			printf("please enter your time selection: (write without .00 please)\n ");
			scanf("%d", &time);
		}


		printf("please enter your name and id: ");
		scanf("%s%s", name, id);



		if (time == 9)				 deleteN(&AvailableTime, 1);
		else if (time == 12)		 deleteN(&AvailableTime, 2);
		else if (time == 15)		 deleteN(&AvailableTime, 3);

		isAvailable = timeSearch(hTime, time);
		if (isAvailable == 1) {
			printf("It has booked, please choose another time.\n");
			return;
		}


		appendN(&hName, name);
		appendN(&hId, id);
		appendCTime(&hTime, time);

		printf("Your book is done.\n\n");
		printf("You can see all books below.\n");
		printBooks(hName, hTime);
		printf("\n");


		printf("Do you want to see the screen again?  (y/n)\n");
		scanf(" %c", &isShow);
		printf("\n");
	}
}

int main(void) {

	question4();

	return 0;
}
