#include <iostream>
#include <iomanip>

using namespace std;

class Time {

private:


	int hour;
	int minute;


public:

	Time(int h = 0, int m = 0);
	Time addTime(Time& a);
	Time operator+(Time& a);
	void prnTime(void);

};

int main(void) {

	Time t1(12, 59), t2(1, 12), t3;

	t1.prnTime();
	t2.prnTime();

	t3 = t1.addTime(t2);

	t3.prnTime();

	t3 = t1 + t2;

	t3.prnTime();


	return 0;
}

Time::Time(int h, int m) {

	hour = h;
	minute = m;

}

Time Time::addTime(Time &a) {

	Time tot;

	int over = 0;

	tot.minute = a.minute + this->minute;

	if (tot.minute >= 60) {
	
		tot.minute = tot.minute % 60;
		over = 1;
	
	}

	tot.hour = a.hour + this->hour + over;

	if (tot.hour >= 24)
		tot.hour = tot.hour % 24;

	return tot;

}

Time Time::operator+(Time& a) {

	Time tot;

	int over = 0;

	tot.minute = a.minute + this->minute;

	if (tot.minute >= 60) {

		tot.minute = tot.minute % 60;
		over = 1;

	}

	tot.hour = a.hour + this->hour + over;

	if (tot.hour >= 24)
		tot.hour = tot.hour % 24;

	return tot;

}

void Time::prnTime(void) {

	cout << setfill('0');
	cout << "The time is --> " << setw(2) << hour << ":" << setw(2) << minute << endl;

}