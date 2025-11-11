#include <string>
#ifndef COSTUMER_H
#define COSTUMER_H

using namespace std;

class Costumer {

private:

	string fname;
	string lname;

public:

	Costumer(void);
	void setFname(void);
	string getFname(void);
	void setLname(void);
	string getLname(void);


};

#endif