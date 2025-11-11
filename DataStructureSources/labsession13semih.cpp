/*
* Programmer: Semih Özkaplan
* Student No: 201504013
* Date:
* Lab Session
*
*/

#include <iostream>
#include <string>

class Shop {

private:

	int count;
	int itemcode[50];
	float itemcost[50];
	float total;



public:
	
	void zeroCount(void);
	void addItem(void);
	void displayTot(void);
	void displayVal(void);
	void dltItem(void);
};

using namespace std;

int main(void) {

		Shop item;

	
		item.zeroCount();


		int choice;

		while (1) {

			cout << "Options are:" << endl;
			cout << "1.    Add an item " << endl;
			cout << "2.    Display total value " << endl;
			cout << "3.    Delete an item " << endl;
			cout << "4.    Display all items " << endl;
			cout << "5.    Exit " << endl;

			cout << "Enter your choice: ";
			cin >> choice;





			switch (choice) {

			case 1:

				item.addItem();
				cout << endl;

				break;

			case 2:

				item.displayTot();
				cout << endl;

				break;

			case 3:

				item.dltItem();
				cout << endl;

				break;

			case 4:

				item.displayVal();
				cout << endl;

				break;

			case 5:

				return 0;

			default:

				cout << "Enter the valid value!!!";

			}

		}
		


	

	return 0;
}




void Shop::addItem(void) {


	cout << "Enter item code: ";
	cin >> itemcode[count];


	cout << "Enter item cost: ";
	cin >> itemcost[count];
	
	count++;

}

void Shop::zeroCount(void) {

	count = 0;

}

void Shop::displayTot(void) {

	int b;
	total = 0;


	for (b = 0; b < count; b++) {

		total = total + itemcost[b];

	}

	cout << "The total is --> " << total << endl;
	

}

void Shop::dltItem(void) {

	int a;

	cout << "Enter the item that you wanna delete: ";
	cin >> a;
	cout << endl;

	for (int i = 0; i < count; i++)
	{

		if (itemcode[a] = a)

			itemcost[a] = 0;

	}


}

void Shop::displayVal(void) {

	int k;

	cout << endl;

	cout << "Item Code" << "      " << "Price" << endl;

	for (k = 0; k < count; k++) {

		cout << itemcode[k] << "         " << itemcost[k] << endl;


	}

	cout << endl;
}