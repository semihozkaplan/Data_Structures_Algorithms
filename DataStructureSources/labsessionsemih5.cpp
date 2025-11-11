/*
* Programmer: Semih Özkaplan
* Student No: 201504013
* Date: 13/05/2022
* Lab Session
*/

#include <iostream>
#include <string>

using namespace std;

class Employee {

	

public:

	int empId, deptId;
	string empName;
	string dept1;
	int salary;

	void setIdName(void) {

		cout << "Please enter your name: ";
		cin >> empName;

		cout << "Please enter your deptID: ";
		cin >> deptId;

		cout << "Please enter empID: ";
		cin >> empId;

		cout << "Please enter your Salary: ";
		cin >> salary;

	}


	};

class Department : public Employee {

public:

	void GetDept(void) {

		switch (deptId) {

		case 100:
			dept1 = "IT";

		case 200:
			dept1 = "PR";

		case 300:
			dept1 = "Manager";
		}

	}

	void CalcSal(void) {

		if (deptId = 100)
			salary = salary * 0.05;
		else if (deptId = 200)
			salary = salary * 0.03;
		else
			salary = salary * 0.1;

	}

	void prnt(void) {

		cout << empName << " your salary is " << salary;

	}

	};

int main(void) {

	Department obj;
	obj.setIdName();
	obj.GetDept();
	obj.CalcSal();
	obj.prnt();

	return 0;
}