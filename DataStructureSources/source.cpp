#include <iostream>

using namespace std;

class Complex {

private:

	int real;
	int image;

public:

	Complex(int r = 0, int i = 0);
	Complex add(Complex& a);
	Complex operator+(Complex& a);
	bool isEqual(Complex& a);
	bool operator==(Complex& a);
	void prnt(void);

};

int main(void) {

	Complex c1(3, 2), c2(3, 5), c3;


	c1.prnt();
	c2.prnt();


	c3 = c1.add(c2);
	c3.prnt();

	c3 = c1 + c2;
	c3.prnt();

	if (c1.isEqual(c2) == true)
		cout << "They are equal" << endl;
	else
		cout << "They are not equal" << endl;

	if (c1 == c2)
		cout << "They are equal" << endl;
	else
		cout << "They are not equal";



	return 0;
}

Complex::Complex(int r, int i) {

	real = r;
	image = i;

}

Complex Complex::add(Complex& a) {

	Complex tot;

	tot.real = this->real + a.real;
	tot.image = this->image + a.image;

	return tot;


}

Complex Complex::operator+(Complex& a) {


	Complex tot;

	tot.real = this->real + a.real;
	tot.image = this->image + a.image;

	return tot;


}

bool Complex::isEqual(Complex& a) {

	if (a.real == this->real && a.image == this->image)
		return true;
	else
		return false;

}
bool Complex::operator==(Complex& a) {

	if (this->real == a.real && this->image == a.image)
		return true;
	else
		return false;

}

void Complex::prnt(void) {

	cout << "The complex number is --> " << real << " + " << image << "i" << endl;

}