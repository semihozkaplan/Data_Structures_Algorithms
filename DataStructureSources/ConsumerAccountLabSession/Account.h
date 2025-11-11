#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Costumer.h"

class Account : public Costumer {

private:

	double balance;
	double rate;

public:

	Account(int b, int r);
	void setBal(double b);
	double getBal(void);
	void setRate(double r);
	double getRate(void);


};

#endif
