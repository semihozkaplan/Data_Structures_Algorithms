#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Try {

private:

	int no;

public:

	Try(int a);
	~Try();

};

void func(void);

Try obj0(0); //Global Object

int main(void) {

	Try obj1(1), obj2(2);

	func();

	Try obj4(4);


	return 0;
}

Try::Try(int a) {

	no = a;

	cout << "Object is created --> " << no << endl;


}

Try::~Try() {

	cout << "Object is destructed --> " << no << endl;

}

void func(void) {

	Try obj3(3);

}