#ifndef _PREDATOR_H_
#define _PREDATOR_H_
#include "Prey.h"


class Predator : public Prey
{
public:
	Predator(Cell*);
	~Predator();
	void live();
	static unsigned int getCount();
	char getName();
	ObjType getType();
protected:
	void breeding();
	bool food();
	static unsigned int count;
	unsigned int timeFood;
};


#endif // !_PREDATOR_H_
