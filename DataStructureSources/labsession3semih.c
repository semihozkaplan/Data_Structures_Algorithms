/*
*
* Programmer: Semih Özkaplan 
* Lab Session 3
* Date: 14.10.2022
* 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {

	char data;
	struct Node* next;

};

void push(struct Node** head_ref, char new_data);
void append(struct Node** head_ref, char new_data);
void printList(struct Node* a);
void insertAfter(struct Node* prev_node, char new_data);
void deleteN(struct Node** head, int position);


int main(void){

	//struct Node* head = NULL;
	//head = (struct Node*)malloc(sizeof(struct Node));

	//head->data = 4;
	//head->next = NULL;


	//push(&head, 6);
	//push(&head, 8);
	//push(&head, 7);
	//push(&head, 1);
	//print(head);
	//printf("\n");
	//
	//deleteN(&head, 1);
	//print(head);
	//printf("\n");
	//deleteN(&head, 4);
	//print(head);
	//printf("\n");
	//deleteN(&head, 2);
	//print(head);
	//printf("\n");

	struct Node* head = NULL;

	head = malloc(sizeof(struct Node*));

	head->data = 'r';
	head->next = NULL;

	append(&head, 'a');
	append(&head, 'i');
	append(&head, 'n');
	append(&head, 'i');
	append(&head, 'n');
	append(&head, 'g');

	printList(head);

	deleteN(&head, 7);
	deleteN(&head, 6);
	deleteN(&head, 5);

	push(&head, 't');
	append(&head, 's');

	printf("\n");
	printList(head);



	

	return 0;
}

void push(struct Node** head_ref, char new_data) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
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

void printList(struct Node* a) {

	while (a != NULL) {

		printf("%c", a->data);
		a = a->next;

	}

}

void insertAfter(struct Node* prev_node, char new_data) {

	if (prev_node == NULL) return;

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = prev_node->next;

	prev_node->next = new_node;

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