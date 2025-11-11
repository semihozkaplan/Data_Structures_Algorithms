/*
* 
* Programmer: Semih Özkaplan
* Student No: 201504013
* Date: 08/04/2022
* Lab Session 2
* 
*/

#include <iostream>

using namespace std;

void reverseString(char x[], int size);
int strlenght(char y[]);

int main(void) {

	char mystr[20];

	cout << "Please enter a string --> " << endl;
	cin >> mystr;
	
	int mystrlen;
	mystrlen = strlenght(mystr);

	reverseString(mystr, mystrlen);


	return 0;
}

void reverseString(char x[], int size) {

	int k = 0;

	while (size + 1 > 0)
	{

		cout << x[size];
		size--;
	}



}

int strlenght(char y[]) {

	int i = 0;

	while (y[i] != '\0') {

		i++;


	}


	return i;
}