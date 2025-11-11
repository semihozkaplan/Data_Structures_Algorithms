/*
*
* Programmer: Semih Özkaplan
* Student No: 201504013
* Date: 08/04/2022
* Lab Session 2
*
*/

#include <iostream>

class Box {


private:
	double height;
	double breadth;
	double length;
	double volume;

public:
	void calculateVol(void);
	void askVol(void);
	void prntVol(void);


};


using namespace std;

int main(void) {

	Box Box1;
	
	Box1.askVol();
	Box1.calculateVol();
	Box1.prntVol();




	return 0;
}

void Box::calculateVol(void) {

	volume = height * length * breadth;

}
void Box::askVol(void) {

	cout << "Please enter the height, lenght and breadth of the box --> ";
	cin >> height >> length >> breadth;

}
void Box::prntVol(void) {

	cout << "The volume of the box is " << volume;

}