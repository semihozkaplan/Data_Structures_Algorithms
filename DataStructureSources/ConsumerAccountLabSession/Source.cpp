#include "Account.h"
#include "Costumer.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main(void) {

	Account c1(121.6, 7);

	cout << fixed;
	cout << setprecision(2);

	cout << c1.getFname() << " " << c1.getLname() << " ";
	cout << "Your balance -- > " << c1.getBal() << endl;
	cout << "Interest Earned -- > " << c1.getBal() * c1.getRate() << endl;

	c1.setBal(c1.getBal() * (1 + c1.getRate()));

	cout << "Your new balance -- > " << c1.getBal() << endl;

	return 0;
}



