#ifndef _CORAL_H_
#define _CORAL_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"

class Coral : public Object
{
protected:
	static unsigned int count;
    unsigned int lifeCycle;
	unsigned int timeBirth;

public:
	Coral(Cell * = nullptr);
	~Coral();
	void live();
	void die();
	void born(Cell *);
	void kill();
	static unsigned int getCount();
};


#endif