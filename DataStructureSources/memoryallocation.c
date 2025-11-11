/*
* Programmer: Semih Özkaplan
* Date: 07/10/2022
* Lab Session2
*/
#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;
	struct node* next;

};

void prntData(struct node *a );
void setFirstData(struct node* a);
//void insertionList(struct node* list, int data1);

int main(void) {

	int userData;

	printf("Please enter your data: ");
	scanf_s("%d", &userData);

	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* second = (struct node*)malloc(sizeof(struct node));
	struct node* third = (struct node*)malloc(sizeof(struct node));
	struct node* fourth = (struct node*)malloc(sizeof(struct node));
	struct node* fifth = (struct node*)malloc(sizeof(struct node));

	struct node* temp = head;
	

	head->data = 15;
	head->next = second;

	second->data = 25;
	second->next = third;

	third->data = 35;
	third->next = fourth;

	fourth->data = 45;
	fourth->next = fifth;

	fifth->data = userData;
	fifth->next = head;

	head->data = userData;
	head->next = NULL;
	

	//int sum = 0;

	//while (temp != NULL) {

	//	sum += temp->data;
	//	temp = temp -> next;

	//}

	//printf("The Sum: %d\n", sum);

	/*insertionList(head, 30);*/

	prntData(head);
	prntData(head);

	return 0;
}

 void prntData(struct node* a) {

	while (a != NULL) 
	{
		
		printf("Data: %d\n", a->data);
		a = a->next;

	}

}

 void setFirstData(struct node* a, struct node* b) {

	 a->next = b;
	 b->next = NULL;

 }

 /*void insertionList(struct node **list, int data1) {

	 struct node *temp;

	 temp = (struct node*)malloc(sizeof(list));
	 temp->data = data1;

	 temp->next = *list;

	 *list = temp;

 }*/