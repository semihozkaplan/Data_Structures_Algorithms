#include <iostream>

using namespace std;


class chocolateMachine {

	float price1;
	float price2;
	float price3;
	float price4;

	int count1;
	int count2;
	int count3;
	int count4;


public:

	void firstLoad1(float f = 2.5, int s = 100);
	void firstLoad2(float a = 3.0, int b = 100);
	void firstLoad3(float a = 5, int b = 50);
	void firstLoad4(float a = 20, int b = 75);
	void giveChocolate();
	void giveWater();
	void giveCandy();
	void giveCookie();
	void show();
	void exit();
	
};

void chocolateMachine::firstLoad1(float f, int s) {

	price1 = f;
	count1 = s;

}

void chocolateMachine::firstLoad2(float a, int b) {

	price2 = a;
	count2 = b;

}

void chocolateMachine::firstLoad3(float a, int b) {

	price3 = a;
	count3 = b;

}

void chocolateMachine::firstLoad4(float a, int b) {

	price4 = a;
	count4 = b;

}

void chocolateMachine::giveChocolate() {

	float payment, change;
	cout << "The cost for chocolate: " << price1 << " $" << endl;
	cout << "How much money will you insert ? ";
	cin >> payment;

	if ((payment >= price1) && (count1 > 0)) {

		cout << "Take your chocolate :)" << endl;
		count1--;
		change = payment - price1;
		if (change > 0) {

			cout << "Your change: ";
			if (change >= 1.0) {
				cout << change << " $" << endl << endl;

			}

			else {

				cout << change * 100 << " cent" << endl;

			}

		}
		else {

			cout << "No chocolate." << endl << endl;
		}
	}
}

void chocolateMachine::giveWater() {

	float payment2, change2;
	cout << "The cost for water: " << price2 << " $" << endl;
	cout << "How much money will you insert ? ";
	cin >> payment2;

	if ((payment2 >= price2) && (count2 > 0)) {

		cout << "Take your water :)" << endl;
		count2--;
		change2 = payment2 - price2;
		if (change2 > 0) {

			cout << "Your change is ";
			if (change2 >= 1.0) {
				cout << change2 << " $" << endl << endl;

			}

			else {

				cout << change2 * 100 << " cent" << endl << endl;

			}

		}
		else {

			cout << "No Water." << endl << endl;
		}
	}

}

void chocolateMachine::giveCandy() {

	float payment3, change3;
	cout << "The cost for candy: " << price3 << " $" << endl;
	cout << "How much money will you insert ? ";
	cin >> payment3;

	if ((payment3 >= price3) && (count3 > 0)) {

		cout << "Take your candy :)" << endl;
		count3--;
		change3 = payment3 - price3;
		if (change3 > 0) {

			cout << "Your change is ";
			if (change3 >= 1.0) {
				cout << change3 << " $" << endl << endl;

			}

			else {

				cout << change3 * 100 << " cent " << endl << endl;

			}

		}
		else {

			cout << "No Candy." << endl << endl;
		}
	}

}
void chocolateMachine::giveCookie() {

	float payment4, change4;
	cout << "The cost for cookie: " << price4 << " $" << endl;
	cout << "How much money will you insert ? ";
	cin >> payment4;

	if ((payment4 >= price4) && (count4 > 0)) {

		cout << "Take your cookie :)" << endl;
		count3--;
		change4 = payment4 - price4;
		if (change4 > 0) {

			cout << "Your change is ";
			if (change4 >= 1.0) {
				cout << change4 << " $" << endl << endl;

			}

			else {

				cout << change4 * 100 << " cent " << endl << endl;

			}

		}
		else {

			cout << "No Cookie." << endl << endl;
		}
	}

}

void chocolateMachine::show() {

	cout << "The machine current situation ---> " << endl << endl;
	cout << "1- Chocolate price: " << price1 << endl;
	cout << "Remaining chocolate: " << count1 << endl << endl;

	cout << "2- Water price: " << price2 << endl;
	cout << "Remaining water: " << count2 << endl << endl;

	cout << "3- Candy price: " << price3 << endl;
	cout << "Remaining candy: " << count3 << endl << endl;

	cout << "4- Cookie price: " << price4 << endl;
	cout << "Remaining cookie: " << count4 << endl << endl;
}



int main(void) {
	
	chocolateMachine cm;

	
	cm.firstLoad1();
	cm.firstLoad2();
	cm.firstLoad3();
	cm.firstLoad4();
	

	while (true) {

		cm.show();

		int sel;

		cout << "Please enter the selection --> ";
		cin >> sel;



		switch (sel) {

		case 1:

			cm.giveChocolate();
			break;

		case 2:

			cm.giveWater();
			break;

		case 3:

			cm.giveCandy();
			break;

		case 4:

			cm.giveCookie();
			break;

		case 5:
			return 0;
			break;

		default:
			cout << "Please enter a valid value!!!" << endl;
		}
	}
	
	cm.show();
	
	
	return 0;
}