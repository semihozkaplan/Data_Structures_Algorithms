#include <iostream>
#include "Water.h"
#define U 7
#define U2 10
#define TH 20

using namespace std;



int main(void) {

	int bill;

	Water w1(15), w2, w3;

	bill = w1.calCons();
	cout << "Your bill is --> " << bill << endl;

	w2.setCons();
	
	cout << "Your consumption is --> " << w2.getCons() << endl;
	qualCost(w2);
	cout << "Your bill is --> " << w2.calCons() << endl;

	w3.setCons();
	qualCost(w3);

	cout << "Your consumption is --> " << w3.getCons() << endl;
	cout << "Your bill is --> " << w3.calCons() << endl;


	return 0;
}



void qualCost(Water &x) {

	char answ;

	cout << "Are you elligable for discount (y / n) --> ";
	cin >> answ;

	if (answ == 'y')
		x.cons = x.cons - TH;

}