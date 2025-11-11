#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node* next;

};

void printList(struct Node* head) {

	while (head) {

		printf("The Data: %d\n", head->data);
		head = head->next;

	}

}

int search(struct Node* head_ref, int x) {

	struct Node* current = head_ref;

	while (current) {

		if (current->data == x)
			return 1;
		
		current = current->next;

	}

	return 0;

}

int searchRec(struct Node* head_ref, int x) {

	if (head_ref == NULL)
		return 0;

	if (head_ref->data == x)
		return 1;

	return searchRec(head_ref->next, x);

}

void push(struct Node** head_ref, int new_data) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;

}

void insertAfter(struct Node* prev_node, int new_data) {

	if (prev_node == NULL)
		printf("Prev Node cannot be NULL");
		return;

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	
	new_node->next = prev_node->next;

	prev_node->next = new_node;


}

void append(struct Node** head_ref, int new_data) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = (*head_ref); // This step for traverse

	new_node->data = new_data;
	new_node->next = NULL;

	if ((*head_ref) == NULL) 
	{
	(*head_ref) = new_node;
	return;
	}
	
	while ((last->next) != NULL) {
		last = last->next;
	}

	last->next = new_node;

}

// Delete item from a list part 1
struct Node* item_ahead(struct Node* head, struct Node* x) {

	if (head == NULL || head->next == NULL)
		return NULL;

	if (head->next == x)
		return head;

	else
	{
		return item_ahead(head->next, x);
	}

}

// Delete item from a list part 2
void delete_list(struct Node** head, struct Node** x) {

	struct Node* p;
	struct Node* pred;

	p = (*head);
	pred = item_ahead(*head, *x);
	
	if (pred == NULL) 
		(*head) = p->next;

	else
	{
		pred->next = (*x)->next;
	}
	
	free(*x);

}

void deleteN(struct Node** head_ref, int position) {

	struct Node* temp;
	struct Node* prev;

	temp = (*head_ref);
	prev = (*head_ref);

	for (int i = 0; i < position; i++)
	{
		if (i == 0 && position == 1)
		{
			(*head_ref) = (*head_ref)->next;
			free(temp);
		}

		else if(i == position - 1 && temp != NULL)
		{			
				prev->next = temp->next;
				free(temp);		
		}

		else
		{
			prev = temp;

			if (prev == NULL)
				break;

			temp = temp->next;

		}

	}

}

struct Node* newNode(int data) {

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = data;

	temp->next = NULL;

	return temp;

}

// Unsorted Linked List Removing Duplicates
void removeDup(struct Node* head_ref) {

	struct Node* ptr1, *ptr2, *dup;

	ptr1 = head_ref;

	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;

		while (ptr2->next != NULL)
		{
			if (ptr1->data == ptr2->next->data)
			{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(dup);
			}

			else
				ptr2 = ptr2->next;
			
		}

		ptr1 = ptr1->next;

	}

}

// Sorted Linked List Removing Duplicates
void removeDupSorted(struct Node* head_ref) {

	struct Node* current = head_ref;

	struct Node* next_next;

	if (current == NULL)
		return;

	while (current->next != NULL)
	{

		if (current->data == current->next->data) {

			next_next = current->next->next;
			free(current->next);
			current->next = next_next;

		}

		else
			current = current->next;

	}

}

// Dummy Method for Taking Two Sorted Linked List Intersection
struct Node* sortedIntersectDummy(struct Node* a, struct Node* b) {

	struct Node dummy;
	struct Node* tail = &dummy;
	dummy.next = NULL;

	while (a != NULL && b != NULL)
	{

		if (a->data == b->data)
		{

			push((&tail->next), a->data);
			tail = tail->next;
			a = a->next;
			b = b->next;

		}

		else if (a->data < b->data)
			a = a->next;

		else
			b = b->next;

	}

	return (dummy.next);

}

// Local Referance Method for Taking Two Sorted Linked List Intersection
struct Node* sortedIntersectRef(struct Node* a, struct Node* b) {

	struct Node* result = NULL;
	struct Node** lastPtrRef = &result; // (*lastPtrRef) points to the result

	while (a != NULL && b!= NULL)
	{

		if (a->data == b->data)
		{
			push(lastPtrRef, a->data);
			lastPtrRef = &((*lastPtrRef)->next);
			a = a->next;
			b = b->next;
		}

		else if (a->data < b->data)
			a = a->next;

		else
			b = b->next;
	}

	return (result);
}

int main(void) {

	struct Node* head = NULL;
	
	push(&head, 12);
	push(&head, 13);
	push(&head, 14);

	printList(head);
	deleteN(&head, 1);

	printf("\n");
	printList(head);


	return 0;
}