#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {

	char data;
	struct Node* next;

};

void printList(struct Node* a);
int search(struct Node* b, char data);
void push(struct Node** head_ref, char new_data);
void insertAfter(struct Node* prev_node, char new_data);
void append(struct Node** head_ref, char new_data);
void deleteN(struct Node** head, int position);

int main(void) {

	struct Node* head = NULL;    
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;
	struct Node* fifth = NULL;
	struct Node* sixth = NULL;
	struct Node* seventh = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	fifth = (struct Node*)malloc(sizeof(struct Node));
	sixth = (struct Node*)malloc(sizeof(struct Node));
	seventh = (struct Node*)malloc(sizeof(struct Node));

	head->data = 'r';
	head->next = second;

	second->data = 'a';
	second->next = third;

	third->data = 'i';
	third->next = fourth;

	fourth->data = 'n';
	fourth->next = fifth;

	fifth->data = 'i';
	fifth->next = sixth;

	sixth->data = 'n';
	sixth->next = seventh;

	seventh->data = 'g';
	seventh->next = NULL;

	printList(head);
	/*int isFound = search(head, 'a');*/
	push(&head, 't');
	printList(head);
	insertAfter(fifth, 'f');
	printList(head);
	append(&head, 'h');
	printList(head);
	deleteN(&head, 10);
	printList(head);

	/*if (isFound == 1) {

		printf("Found it");

	}

	else {

		printf("Nothing");

	}*/

	return 0;
}

void printList(struct Node* a) {
	
	while (a != NULL) {

		printf("%c", a->data);
		a = a->next;

	}
	
}

int search(struct Node* b, char data) {

	struct Node* current = b;

	while (current != NULL) {

		if (current->data == data) {

			return 1;

		}

		current = current->next;

	}

	return 0;

}

void push(struct Node** head_ref, char new_data) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, char new_data) {

	if (prev_node == NULL) return;

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	
	new_node->next = prev_node->next;

	prev_node->next = new_node;

}

void append(struct Node** head_ref, char new_data) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = (*head_ref);

	new_node->data = new_data;

	new_node->next = NULL;

	if ((*head_ref) == NULL) {

		(*head_ref) = new_node;
		return;

	}
	
	while (last->next != NULL) {

		last = last->next;

	}

	last->next = new_node; //Else
	return;
}

void deleteN(struct Node** head, int position)
{
	struct Node* temp;
	struct Node* prev;

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
