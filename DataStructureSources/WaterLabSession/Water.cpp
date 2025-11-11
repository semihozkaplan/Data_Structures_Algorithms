#include "Water.h"
#include <iostream>
#define TH 20
#define U 7
#define U2 10

using namespace std;

Water::Water(int c) {

	cons = c;

}

Water::~Water() {

	cout << "Please pay your consuption in time !!!" << endl;

}

void Water::setCons(void) {

	cout << "Please enter your consumption --> ";
	cin >> cons;

}

int Water::getCons(void) {

	return cons;

}

int Water::calCons(void) {

	if (getTh() == 0)
		return cons * U;

	else
		return TH * U + (cons - TH) * U2;

}

int Water::getTh(void) {

	if (cons > TH)
		return 1;

	else
		return 0;

}