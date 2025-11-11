#include "Costumer.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Costumer::Costumer(void) {

	setFname();
	setLname();

}

void Costumer::setFname(void) {

	cout << "First Name --> ";
	cin >> fname;

}

string Costumer::getFname(void) {

	return fname;

}

void Costumer::setLname(void) {

	cout << "Last Name --> ";
	cin >> lname;

}

string Costumer::getLname(void) {

	return lname;

}