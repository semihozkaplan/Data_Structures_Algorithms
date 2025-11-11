#include "Costumer.h"
#include "Account.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Account::Account(int b, int r) {

	setBal(b);
	setRate(r);

}

void Account::setBal(double b) {

	balance = b;

}

double Account::getBal(void) {

	return balance;

}

void Account::setRate(double r) {

	rate = r;

}

double Account::getRate(void) {

	return rate;

}