#ifndef _PREY_H_
#define _PREY_H_
#include "Object.h"


class Prey : public Object
{
public:
	Prey(Cell * = nullptr);
	~Prey();
	void live();
	static unsigned int getCount();
	ObjType getType();
	char getName();
protected:
	void move();
	virtual void breeding();
	static unsigned int count;
	
	unsigned int liveTime;
	unsigned int liveBreeding;
};


#endif