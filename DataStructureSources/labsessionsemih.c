/*
*
*Programmer: Semih Özkaplan
*Student No: 201504013
*Lab Session 1
*
*/

#include <stdio.h>
#include <math.h>

struct Person {

	int age;
	float weight;

};


int main(void) {

	/*int arr[3] = { 10, 100, 1000 };

	int* ptr;

	ptr = arr;

	for (int i = 0; i < 3; i++)
	{

		printf("Value of the *ptr : %d\n", *ptr);
		(*ptr)++;
		


	}*/

	struct Person person1;
	struct Person* personptr;

	personptr = &person1;

	printf("Please enter your age: ");
	scanf_s("%d", &(personptr -> age));

	printf("Please enter your weight: ");
	scanf_s("%d", &(personptr -> weight));

	printf("%d", person1.age);
	printf("%f", person1.weight);


	return 0;

}