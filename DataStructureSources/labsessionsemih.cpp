/*
 Programmer: Semih Özkaplan
 Date: 29/04/2022
 Lab Session
*/

#include <iostream>
#include <string>

using namespace std;


class ChocolateMachine {


private:

	float price;
	int count;


public:
	
	void FirstLoad(float f = 2.5, int s = 100);
	void GiveChocolate();
	void show();

};

int main(void) {

	ChocolateMachine cm;

	cm.FirstLoad();
	cm.GiveChocolate();
	cm.show();

	return 0;
}

void ChocolateMachine::FirstLoad(float f = 2.5, int s = 100) {

	price = f;
	count = s;

}

void ChocolateMachine::GiveChocolate() {

	float payment, change;

	cout << "The cost of chocolate : " << price << " $." << endl;
	cout << "How much money will you insert ?";
	cin >> payment;

	if ((payment >= price) && (count > 0)) {

		cout << "Take your chocolate :)" << endl;
		count--;

		change = payment - price;

		if (change > 0) {
			cout << "Your change -->  ";

			if (change > 1.0)
				cout << change << "$" << endl;

			else
				cout << change * 100 << " cent" << endl;
		}
	}

	else
		cout << "No chocolate.";
}

void ChocolateMachine::show() {

	cout << "The machine current situation is --> " << endl;
	cout << "Chocolate price: " << price << endl;
	cout << "Remaining chocolate: " << count << endl;

}