#ifndef WATER_H
#define WATER_H

class Water {

	friend void qualCost(Water& x); // Friend Func

private:

	int cons;
	int getTh(void); // Helper func


public:

	Water(int c = 0);
	~Water();
	void setCons(void); // Access Set
	int getCons(void);  // Access Get
	int calCons(void);

};

#endif
