#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <windows.h>

using namespace std;

class Pipe {

private:

		int n1 = 3;
		int n2 = 3;
		int n3 = 3;
		int n4 = 4;
		int n5 = 4;
		double t;
		int num1;
		int num2;
		int num3;
		int num4;
		int num5;
		double res1 = 0;
		double res2 = 0;
		double res3 = 0;
		double res4 = 0;
		double res5 = 0;
	

public:

	void setTime(void);
	void twentyMm(void);
	void fourtyMm(void);
	void sixtyMm(void);
	void eightyMm(void);
	void hunderedMm(void);
	

};

int main(void) {

	system("color 9");
	Pipe pp1;

	int select;
	char dec;
	char dec2;

	cout << "                      ***Welcome to Calculating Pipe Flow Program***" << endl;
	cout << endl;
	cout << "  Notes: " << endl;
	cout << endl;
	cout << "  ** This program will calculate instantaneous velocity of water passing through the pipe " << endl;
	cout << "  ** These equations given below are random " << endl;
	cout << "  ** This program takes the derivative of the formulas given below according to the desired second without any errors";
	cout << endl;
	cout << endl;

	cout << "   1. 20 mm Pipe Radius --> The formula of velocity due to the variable t is 2t^3 + 2t^2 + 5t " << endl;
	cout << endl;
	cout << "   2. 40 mm Pipe Radius --> The formula of velocity due to the variable t is 4t^3 + 5t^2 + 8t " << endl;
	cout << endl;
	cout << "   3. 60 mm Pipe Radius --> The formula of velocity due to the variable t is 3t^3 + 5t^2 + 2t " << endl;
	cout << endl;
	cout << "   4. 80 mm Pipe Radius --> The formula of velocity due to the variable t is t^4 + 5t^3 + 2t^2 + 2t " << endl;
	cout << endl;
	cout << "   5. 100 mm Pipe Radius --> The formula of velocity due to the variable t is t^4 + 3t^3 + 6t^2 + 1t " << endl;
	cout << endl;


	cout << "  Please select a type of radius shown ebove ---> ";
	cin >> select;
	cout << endl;

	pp1.setTime();

		
		switch (select) {

		case 1:
			pp1.twentyMm();
			cout << endl;
			
			break;

		case 2:
			pp1.fourtyMm();
			cout << endl;

			break;

		case 3:
			pp1.sixtyMm();
			cout << endl;

			break;

		case 4:
			pp1.eightyMm();
			cout << endl;

			break;

		case 5:
			pp1.hunderedMm();
			cout << endl;

			break;

		default:
			cout << "Please enter a valid value !!!" << endl;
			
		}
	

	return 0;
}

void Pipe::setTime(void) {

	cout << "  Please enter the instant time you want to find out ---> ";
	cin >> t;

}



void Pipe::twentyMm(void) {

	for (n1; n1 > 0; n1--) {

		cout << "  Please enter the " << "t^" << n1 << " coefficent that is shown above ---> ";
		cin >> num1;
		res1 += n1 * num1 * pow(t, n1 - 1);
		num1 = 0;

	}

	
	cout << endl;
	cout << "  The Derivative or instant velocity where time = " << t << " is " << res1;
	t = 0;
	
}
void Pipe::fourtyMm(void) {

	for (n2; n2 > 0; n2--) {

		cout << "  Please enter the " << "t^" << n2 << " coefficent that is shown above ---> ";
		cin >> num2;
		res2 += n2 * num2 * pow(t, n2 - 1);
		num2 = 0;

	}


	cout << endl;
	cout << "  The Derivative or instant velocity where time = " << t << " is " << res2;
	t = 0;
}
void Pipe::sixtyMm(void) {

	for (n3; n3 > 0; n3--) {

		cout << "  Please enter the " << "t^" << n3 << " coefficent that is shown above ---> ";
		cin >> num3;
		res3 += n3 * num3 * pow(t, n3 - 1);
		num3 = 0;

	}


	cout << endl;
	cout << "  The Derivative or instant velocity where time = " << t << " is " << res3;
	t = 0;
}

void Pipe::eightyMm(void) {

	for (n4; n4 > 0; n4--) {

		cout << "  Please enter the " << "t^" << n4 << " coefficent that is shown above ---> ";
		cin >> num4;
		res4 += n4 * num4 * pow(t, n4 - 1);
		num4 = 0;

	}


	cout << endl;
	cout << "  The Derivative or instant velocity where time = " << t << " is " << res4;
	t = 0;

}

void Pipe::hunderedMm(void) {

	for (n5; n5 > 0; n5--) {

		cout << "  Please enter the " << "t^" << n5 << " coefficent that is shown above ---> ";
		cin >> num5;
		res5 += n5 * num5 * pow(t, n5 - 1);
		num5 = 0;

	}


	cout << endl;
	cout << "  The Derivative or instant velocity where time = " << t << " is " << res5;
	t = 0;

}