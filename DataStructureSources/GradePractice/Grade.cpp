#include <iostream>
#include <string>
#include "Grade.h"

using namespace std;

void Grade::setGrd(void) {

	cout << "Please enter your midterm, final and lab grades: " << endl;
	cin >> mid >> final >> lab;

	total = .3 * mid + .4 * final + .3 * lab;

}


void Grade::prntGrd(void) {

	cout << "The total grade --> " << total << endl;


}