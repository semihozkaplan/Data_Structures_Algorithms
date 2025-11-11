/*
*
* Programmer: Semih Özkaplan
* Data Structure And Algorithms: Homework 1
* Date: 17.10.2022
* 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// I made a struct as a node here to occur a linked list
struct Node
{ 

	int data;
	char name[10];
	char spellName;
	struct Node* next;

};

// This structure has made for Health System 
struct NodeH 
{

	int time; 
	char name[10];
	char id_number[10];
	int timeFlag;
	struct NodeH* next;

};

void prntList(struct Node* a); // This func is for Question 1 and 2 to print the numbers.
void prntListName(struct Node* a); // This func is for Question 3 to print my family names.
void prntListTimeH(struct NodeH* a); // This func is for Question 4 to print patiens booking time.
void prntPatients(struct NodeH* a, struct NodeH* b, struct NodeH* c, struct NodeH* d); // This func is for Question 4 to print patiens informations(name, ID etc.).
void prntListChar(struct Node* a); // This func is for Question 6 to print my name as char .
void push(struct Node** head_ref, int new_data); // Push func.
void pushString(struct Node** head_ref, char new_data[]); // This function can push a string instead of number.
void pushChar(struct Node** head_ref, char new_data);  // This function can push a char instead of number.
void insertAfter(struct Node* prev_node, int new_data); // Insert After func.
void insertAfterChar(struct Node* prev_node, char new_data);  // This function can insert after a char instead of number.
void insertAfterName(struct Node* prev_node, char new_data[]); // This function can insret after a string instead of number.
void append(struct Node** head_ref, int new_data);        // This is the int append func. for struct Node
void appendName(struct Node** head_ref, char new_data[]); // This is the string append func. for struct Node
void appendNameH(struct NodeH** head_ref, char new_data[]); // This is the string append func. for struct NodeH
void appendTimeH(struct NodeH** head_ref, int new_data);    // This is the int append func. for struct NodeH
void appendChar(struct Node** head_ref, char new_data); // This is the int append func. to append a char
void deleteNode(struct Node** head, int position); // This is the int delete func. to delete a node from a list
void deleteNodeTimeH(struct NodeH** head, int position); // This is the int delete func. for Health System struct NodeH to delete a node from a list
int searchTimeH(struct NodeH* b, int timeData); // This is a iteratively search func. to find an available time.
int searchNameH(struct NodeH* b, char name[]);  // This is a iteratively search func. to find a string.
void question1and2(); // Question 1 and 2
void question3(); // Question 3
void question4(); // Question 4
void question5(); // Question 5
void question6(); // Question 6


int main(void) 
{

	//Interface of the program
	int qNumber;

	printf("---Welcome To My Homework---\n\n");
	printf("1.Question (Question 1 and 2)\n");
	printf("3.Question\n");
	printf("4.Question\n");
	printf("5.Question\n");
	printf("6.Question\n\n");
	
	printf("Please enter the question code that you want to access --> ");
	scanf(" %d", &qNumber);

	// Switch - Case operation to open the questions
	switch (qNumber) {

	case 1:
		question1and2();
		break;

	case 3:
		question3();
		break;

	case 4:
		question4();
		break;

	case 5:
		question5();
		break;

	case 6:
		question6();
		break;

	default:
		printf("Please enter a valid value !!!\n");

	}

	
	return 0;
}

void prntList(struct Node* a) 
{

	while (a != NULL) 
	{
		printf("The Data: %d\n", a->data);
		a = a->next;
	}

}

void prntListName(struct Node* a)
{

	while (a != NULL)
	{

		printf("The Data: %s\n", a->name);
		a = a->next;
	}

}

void prntListTimeH(struct NodeH* a)
{

	while (a != NULL)
	{

		printf("Available Time --> %d:00\n", a->time);
		a = a->next;
	}

}

void prntPatients(struct NodeH* a, struct NodeH* b, struct NodeH* c, struct NodeH* d)
{

	int patientNumber = 1;

	while (a != NULL && b != NULL && c != NULL && d != NULL)
	{
		

		printf("The Choosen Clinic --> %s\n", c->name);
		printf("Patient Number, Patient Name, Choosen Day and Time --> %d -> %s %s %d:00 \n",patientNumber ,a->name, d->name, b->time);
		printf("\n");
		a = a->next;
		b = b->next;
		c = c->next;
		d = d->next;

		++patientNumber;
	}

}

void prntListChar(struct Node* a)
{

	while (a != NULL)
	{
		printf("%c", a->spellName);
		a = a->next;
	}

}

void push(struct Node** head_ref, int new_data) 
{

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void pushChar(struct Node** head_ref, char new_data)
{

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->spellName = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void pushString(struct Node** head_ref, char new_data[])
{

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	strcpy(new_node->name, new_data); // We cannot change the stirng directly, so I used strcpy() for this.

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data) 
{
	
	if (prev_node == NULL) 
	{

		printf("Not found a node! Check it !!");
		return;

	}

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = prev_node->next;

	prev_node-> next = new_node;
}

void insertAfterChar(struct Node* prev_node, char new_data)
{

	if (prev_node == NULL)
	{

		printf("Not found a node! Check it !!");
		return;

	}

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->spellName = new_data;

	new_node->next = prev_node->next;

	prev_node->next = new_node;
}

void insertAfterName(struct Node* prev_node, char new_data[])
{

	if (prev_node == NULL)
	{

		printf("Not found a node! Check it !!");
		return;

	}

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	strcpy(new_node->name, new_data);

	new_node->next = prev_node->next;

	prev_node->next = new_node;
}

void append(struct Node** head_ref, int new_data) 
{

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last =  (*head_ref); // We will use this below

	new_node->data = new_data;

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

void appendChar(struct Node** head_ref, char new_data)
{

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = (*head_ref); // We will use this below

	new_node->spellName = new_data;

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

void appendName(struct Node** head_ref, char new_data[])
{

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = (*head_ref); // We will use this below

	strcpy(new_node->name, new_data);

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

void appendTimeH(struct NodeH** head_ref, int new_data)  // Apppend for question 4
{

	struct NodeH* new_node = (struct NodeH*)malloc(sizeof(struct NodeH));

	struct NodeH* last = (*head_ref); // We will use this below

	new_node->time = new_data;

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

void appendNameH(struct NodeH** head_ref, char new_data[])
{

	struct NodeH* new_node = (struct NodeH*)malloc(sizeof(struct NodeH));

	struct NodeH* last = (*head_ref); // We will use this below

	strcpy(new_node->name, new_data);

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

void deleteNode(struct Node** head, int position)
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

				if (prev == NULL)
					break;

				temp = temp->next;

			}
		}
	}
}


void deleteNodeTimeH(struct NodeH** head, int position)
{
	struct NodeH* temp;
	struct NodeH* prev;

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

				if (prev == NULL)
					break;

				temp = temp->next;

			}
		}
	}
}

int searchTimeH(struct NodeH* b, int timeData) {

	struct NodeH* current = b;

	while (current != NULL) {

		if (current->time == timeData) {

			return 1;

		}

		current = current->next;

	}

	return 0;

}

int searchNameH(struct NodeH* b, char name[]) {

	struct NodeH* current = b;

	while (current != NULL) {

		if (current->name == name) {

	
			return 1;

		}

		current = current->next;

	}

	return 0;

}

void question1and2(void)
{

	struct Node* head = NULL; // I declare a head of linked list here

	// Question 1
	push(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insertAfter(head->next, 8);

	prntList(head);
	printf("\n");

	// Question 2
	deleteNode(&head, 1);
	deleteNode(&head, 4);
	deleteNode(&head, 2);
	
	printf("After deleting, the situation of datas: \n");
	prntList(head);
	printf("\n");


}

void question3(void) {

	// Question 3
	struct Node* head = NULL;

	pushString(&head, "Semih");
	pushString(&head, "Enes");
	pushString(&head, "Oguz");
	appendName(&head, "Nihal");
	insertAfterName(head->next, "Taha");
	prntListName(head);
	printf("\n");

}

void question4(void) {

	//Question 4
	struct NodeH* headAvailableTime = NULL; // This stores the available time datas.
	struct NodeH* headClinic = NULL; // This stores the all clinics
	struct NodeH* headDay = NULL;   // This stores the days.
	struct NodeH* headTime = NULL; // This stores the users booked times.
	struct NodeH* headName = NULL; // This stores names of users.
	struct NodeH* headID = NULL;   // This stores IDs of users.
	
	int timeFlag; // I decelare a flag to delete the correct time from the list, if it has booked.
	char yN = 'n'; // This is for question if it is yes, you can see the list.
	int timeH = 0; 
	char nameH[15];
	char id_numberH[15];
	char clinic_nameH[20];
	char dayH[10];
	
	appendTimeH(&headAvailableTime, 12);
	appendTimeH(&headAvailableTime, 13);
	appendTimeH(&headAvailableTime, 14);
	appendTimeH(&headAvailableTime, 15);
	appendTimeH(&headAvailableTime, 16);

	printf("***Welcome to My Health System***\n\n");
	
	printf("Do you want to see the lists ? (y/n) ->> ");
	scanf(" %c", &yN);
	printf("\n");

	if (yN == 'n') {

		printf("HAVE A GOOD DAYY :))");

	}

	while (yN == 'y') {

		printf("Clinic List --> \n");
		printf("--> Cardiologist\n");
		printf("--> Dermatologist\n");
		printf("--> Physician\n");
		printf("--> Paediatrician\n");
		printf("\n");

		// Print the available time linked list
		prntListTimeH(headAvailableTime);

		printf("Please choose a Clinic from above ->>");
		scanf("%s", clinic_nameH);
		printf("\n");

		printf("Please enter your name ->> ");
		scanf("%s", nameH);
		printf("\n");

		printf("Please enter your ID ->> ");
		scanf("%s", id_numberH);
		printf("\n");

		printf("Please enter a day for booking ->>");
		scanf("%s", dayH);
		printf("\n");

		printf("Please enter a available time(-Enter only left side of the time-) ->> ");
		scanf(" %d", &timeH);
		printf("\n");

		// Delete the correct time node that users have booked.

		switch (timeH) {

		case 12:
			timeFlag = 1;
			deleteNodeTimeH(&headAvailableTime, timeFlag);
			break;

		case 13:
			timeFlag = 2;
			deleteNodeTimeH(&headAvailableTime, timeFlag - 1);
			break;

		case 14:
			timeFlag = 3;
			deleteNodeTimeH(&headAvailableTime, timeFlag - 1);
			break;

		case 15:
			timeFlag = 4;
			deleteNodeTimeH(&headAvailableTime, timeFlag - 1);
			break;

		case 16:
			timeFlag = 5;
			deleteNodeTimeH(&headAvailableTime, timeFlag - 1);
			break;

		default:
			printf("Exception Error: Please enter a valid value !!");
			return;

		}

		// Search if time is not taken. If it is --> return; and stop the program.

		int isAvailable = searchTimeH(headTime, timeH);

			if (isAvailable == 1) { // Check if it is available, 1 means it is not available.

				printf("It has booked from someone, try again !\n");
				return;
			}
	
		appendNameH(&headName, nameH);
		appendNameH(&headID, id_numberH);
		appendTimeH(&headTime, timeH);
		appendNameH(&headClinic, clinic_nameH);
		appendNameH(&headDay, dayH);

		printf("You have booked :) Please follow your book\n\n");

		printf("The users that booked below -->\n");
		prntPatients(headName, headTime, headClinic, headDay);
		printf("\n");

		printf("Do you want to see the lists again ? (y/n) ->> ");
		scanf(" %c", &yN);
		printf("\n");

	}

}

void question5(void) {

	//Question 5
	struct NodeH* headAvailableTime = NULL; // This stores the available time datas.
	struct NodeH* headCurrentClinic = NULL; // This stores the all clinics
	struct NodeH* headCurrentDay = NULL;   // This stores the days.
	struct NodeH* headCurrentTime = NULL; // This stores the users booked times.
	struct NodeH* headPatientCurrentName = NULL; // This stores names of users.
	struct NodeH* headCurrentID = NULL;   // This stores IDs of users.

	int patientNumber;
	char isCheckIn = 'n';
	int timeFlag; // I decelare a flag to delete the correct time from the list, if it has booked.
	char yN = 'n'; // This is for question if it is yes, you can see the list.
	int timeH = 0;
	char nameH[15];
	char id_numberH[15];
	char clinic_nameH[20];
	char dayH[10];

	appendTimeH(&headAvailableTime, 12);
	appendTimeH(&headAvailableTime, 13);
	appendTimeH(&headAvailableTime, 14);
	appendTimeH(&headAvailableTime, 15);
	appendTimeH(&headAvailableTime, 16);

	printf("***Welcome to My Health System***\n\n");

	printf("Do you want to see the lists ? (y/n) ->> ");
	scanf(" %c", &yN);
	printf("\n");

	if (yN == 'n') {

		printf("HAVE A GOOD DAYY :))");

	}

	while (yN == 'y') {

		printf("Clinic List --> \n");
		printf("--> Cardiologist\n");
		printf("--> Dermatologist\n");
		printf("--> Physician\n");
		printf("--> Paediatrician\n");
		printf("\n");

		// Print the available time linked list
		prntListTimeH(headAvailableTime);

		printf("Please choose a Clinic from above ->>");
		scanf("%s", clinic_nameH);
		printf("\n");

		printf("Please enter your name ->> ");
		scanf("%s", nameH);
		printf("\n");

		printf("Please enter your ID ->> ");
		scanf("%s", id_numberH);
		printf("\n");

		printf("Please enter a day for booking ->>");
		scanf("%s", dayH);
		printf("\n");

		printf("Please enter a available time(-Enter only left side of the time-) ->> ");
		scanf("%d", &timeH);
		printf("\n");


		// Delete the correct time node that users have booked.

		switch (timeH) {

		case 12:
			timeFlag = 1;
			deleteNodeTimeH(&headAvailableTime, timeFlag);
			break;

		case 13:
			timeFlag = 2;
			deleteNodeTimeH(&headAvailableTime, timeFlag - 1);
			break;

		case 14:
			timeFlag = 3;
			deleteNodeTimeH(&headAvailableTime, timeFlag - 1);
			break;

		case 15:
			timeFlag = 4;
			deleteNodeTimeH(&headAvailableTime, timeFlag - 1);
			break;

		case 16:
			timeFlag = 5;
			deleteNodeTimeH(&headAvailableTime, timeFlag - 1);
			break;

		default:
			printf("Exception Error: Please enter a valid value !!");
			return;

		}

		// Search if time is not taken. If it is --> return; and stop the program.

		int isAvailable = searchTimeH(headCurrentTime, timeH);

		if (isAvailable == 1) { // Check if it is available, 1 means it is not available.

			printf("It has booked from someone, try again !\n");
			return;
		}

		appendNameH(&headPatientCurrentName, nameH);
		appendNameH(&headCurrentID, id_numberH);
		appendTimeH(&headCurrentTime, timeH);
		appendNameH(&headCurrentClinic, clinic_nameH);
		appendNameH(&headCurrentDay, dayH);


		printf("You have booked :) Please follow your book\n\n");

		printf("The users that booked below -->\n\n");
		prntPatients(headPatientCurrentName, headCurrentTime, headCurrentClinic, headCurrentDay);
		printf("\n");

		printf("Have you checked-in by Doctor ? (y/n)");
		scanf(" %c", &isCheckIn);

		if (isCheckIn == 'y') 
		{

			printf("Please enter the patient that have checked-in --> ");
			scanf("%d", &patientNumber);
			printf("\n");

			switch (patientNumber) {  // Choose the correct node to delete that have checked-in

			case 1: 
				deleteNodeTimeH(&headPatientCurrentName, 1);
				deleteNodeTimeH(&headCurrentID, 1);
				deleteNodeTimeH(&headCurrentTime, 1);
				deleteNodeTimeH(&headCurrentClinic, 1);
				deleteNodeTimeH(&headCurrentDay, 1);
				printf("After Check in, The list is below ---> \n");
				
				if (headPatientCurrentName == NULL && headCurrentID == NULL && headCurrentTime == NULL && headCurrentClinic == NULL &&
					headCurrentDay == NULL) {

					printf("There is no patient --> Let Doctor have a rest :)\n");

				}

				prntPatients(headPatientCurrentName, headCurrentTime, headCurrentClinic, headCurrentDay);
				printf("\n");
				break;

			case 2:
				deleteNodeTimeH(&headPatientCurrentName, 2);
				deleteNodeTimeH(&headCurrentID, 2);
				deleteNodeTimeH(&headCurrentTime, 2);
				deleteNodeTimeH(&headCurrentClinic, 2);
				deleteNodeTimeH(&headCurrentDay, 2);
				printf("After Check in, The list is below ---> \n");

				if (headPatientCurrentName == NULL && headCurrentID == NULL && headCurrentTime == NULL && headCurrentClinic == NULL &&
					headCurrentDay == NULL) {

					printf("There is no patient --> Let Doctor have a rest :)\n");

				}

				prntPatients(headPatientCurrentName, headCurrentTime, headCurrentClinic, headCurrentDay);
				printf("\n");
				break;

			case 3:
				deleteNodeTimeH(&headPatientCurrentName, 3);
				deleteNodeTimeH(&headCurrentID, 3);
				deleteNodeTimeH(&headCurrentTime, 3);
				deleteNodeTimeH(&headCurrentClinic, 3);
				deleteNodeTimeH(&headCurrentDay, 3);
				printf("After Check in, The list is below ---> \n");

				if (headPatientCurrentName == NULL && headCurrentID == NULL && headCurrentTime == NULL && headCurrentClinic == NULL &&
					headCurrentDay == NULL) {

					printf("There is no patient --> Let Doctor have a rest :)\n");

				}

				prntPatients(headPatientCurrentName, headCurrentTime, headCurrentClinic, headCurrentDay);
				printf("\n");
				break;

			case 4:
				deleteNodeTimeH(&headPatientCurrentName, 4);
				deleteNodeTimeH(&headCurrentID, 4);
				deleteNodeTimeH(&headCurrentTime, 4);
				deleteNodeTimeH(&headCurrentClinic, 4);
				deleteNodeTimeH(&headCurrentDay, 4);
				printf("After Check in, The list is below ---> \n");

				if (headPatientCurrentName == NULL && headCurrentID == NULL && headCurrentTime == NULL && headCurrentClinic == NULL &&
					headCurrentDay == NULL) {

					printf("There is no patient --> Let Doctor have a rest :)\n");

				}

				prntPatients(headPatientCurrentName, headCurrentTime, headCurrentClinic, headCurrentDay);
				printf("\n");
				break;

			case 5:
				deleteNodeTimeH(&headPatientCurrentName, 5);
				deleteNodeTimeH(&headCurrentID, 5);
				deleteNodeTimeH(&headCurrentTime, 5);
				deleteNodeTimeH(&headCurrentClinic, 5);
				deleteNodeTimeH(&headCurrentDay, 5);
				printf("After Check in, The list is below ---> \n");

				if (headPatientCurrentName == NULL && headCurrentID == NULL && headCurrentTime == NULL && headCurrentClinic == NULL &&
					headCurrentDay == NULL) {

					printf("There is no patient --> Let Doctor have a rest :)\n");

				}

				prntPatients(headPatientCurrentName, headCurrentTime, headCurrentClinic, headCurrentDay);
				printf("\n");
				break;

			default:
				printf("There is no patient that have a number like that !!");
			}

		}
			

		printf("Do you want to see the lists again ? (y/n) ->> ");
		scanf(" %c", &yN);
		printf("\n");

	}

}

void question6(void) {

	//Question 6
	struct Node* head = NULL;

	appendChar(&head, 'S');
	appendChar(&head, 'e');
	appendChar(&head, 'm');
	appendChar(&head, 'i');
	appendChar(&head, 'h');
	appendChar(&head, ' ');
	appendChar(&head, 'O');
	appendChar(&head, 'Z');
	appendChar(&head, 'K');
	appendChar(&head, 'A');
	appendChar(&head, 'P');
	appendChar(&head, 'L');
	appendChar(&head, 'A');
	appendChar(&head, 'N');

	prntListChar(head);
	printf("\n");

	deleteNode(&head, 6);
	deleteNode(&head, 5);
	deleteNode(&head, 4);
	deleteNode(&head, 3);
	deleteNode(&head, 2);
	deleteNode(&head, 1);
	appendChar(&head, ' ');
	appendChar(&head, 'S');
	appendChar(&head, 'e');
	appendChar(&head, 'm');
	appendChar(&head, 'i');
	appendChar(&head, 'h');

	prntListChar(head);
	printf("\n");

	deleteNode(&head, 9);
	deleteNode(&head, 8);
	deleteNode(&head, 7);
	deleteNode(&head, 6);
	deleteNode(&head, 5);
	deleteNode(&head, 4);
	deleteNode(&head, 3);
	deleteNode(&head, 2);
	deleteNode(&head, 1);

	struct Node* headSecondList = NULL;

	appendChar(&headSecondList, ' ');
	appendChar(&headSecondList, 'O');
	appendChar(&headSecondList, 'Z');
	appendChar(&headSecondList, 'K');
	appendChar(&headSecondList, 'A');
	appendChar(&headSecondList, 'P');
	appendChar(&headSecondList, 'L');
	appendChar(&headSecondList, 'A');
	appendChar(&headSecondList, 'N');

	// This appends a char into the next node
	appendChar(&head, headSecondList->spellName); 
	appendChar(&head, headSecondList->next->spellName);
	appendChar(&head, headSecondList->next->next->spellName);
	appendChar(&head, headSecondList->next->next->next->spellName);
	appendChar(&head, headSecondList->next->next->next->next->spellName);
	appendChar(&head, headSecondList->next->next->next->next->next->spellName);
	appendChar(&head, headSecondList->next->next->next->next->next->next->spellName);
	appendChar(&head, headSecondList->next->next->next->next->next->next->next->spellName);
	appendChar(&head, headSecondList->next->next->next->next->next->next->next->next->spellName);

	prntListChar(head);
	printf("\n");

}