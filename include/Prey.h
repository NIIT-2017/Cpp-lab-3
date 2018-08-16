#ifndef _PREY_H_
#define _PREY_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"

class Prey : public Object
{
protected:
	static unsigned int count;
    unsigned int lifeCycle;
	unsigned int timeBirth;
    bool isEat;
	bool isReproduce;

public:
	Prey(Cell * = nullptr);
	~Prey();
	void live();
	void die();
	void born(Cell *);
    void move();
    void kill();
    virtual bool eat(Cell *);
	static unsigned int getCount();
};


#endif