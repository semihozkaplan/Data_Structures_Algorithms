#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date {

private:

	int dy;
	int mo;
	int yr;

public:

	Date(int d, int m, int y);
	void setDt(int d, int m, int y);
	void prntDtUS(void);
	void prntDt(void);

};

int main(void) {

	Date bday(1, 4, 2001);

	int day;
	int month;
	int year;

	cout << "Please enter your birthday(dd.mm.yy) --> ";
	cin >> day >> month >> year;

	bday.setDt(day, month, year);
	bday.prntDt();
	bday.prntDtUS();


	return 0;
}

	Date::Date(int d, int m, int y) {
		
		setDt(d, m, y);
		cout << "This is the constuructor date part" << endl;
		cout << d << "." << m << "." << y << endl;
		
}
	void Date::setDt(int d, int m, int y) {

		dy = d;
		mo = m;
		yr = y;

}
	
	void Date::prntDt() {

		cout << "Your date is --> " << dy << "." << mo << "." << yr << endl;


}
	void Date::prntDtUS() {

		string mn;
			
		switch (mo) {
			
		case 1:
			mn = "Ocak";

		case 2:
			mn = "Þubat";

		case 3:
			mn = "Mart";

		case 4:
			mn = "Nisan";

		case 5:
			mn = "Mayýs";

		case 6:
			mn = "Haziran";

		case 7:
			mn = "Temmuz";

		case 8:
			mn = "Aðustos";

		case 9:
			mn = "Eylül";

		case 10:
			mn = "Ekim";

		case 11:
			mn = "Kasým";

		case 12:
			mn = "Aralýk";



		}

		cout << "US Date is " << mn << " " << dy << " " << yr << endl;

}
	