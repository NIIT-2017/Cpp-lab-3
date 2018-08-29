#ifndef _PREDATOR_H_
#define _PREDATOR_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"

class Predator : public Object
{
protected:
	static unsigned int count;
    unsigned int lifeCycle;
    unsigned int timeBirth;
    unsigned int feedCycle;
    unsigned int eatCycle;
    bool isEat;
    bool isReproduce;

public:
	Predator(Cell * = nullptr);
	~Predator();
	void live();
	void die();
	void born(Cell *);
    void move();
    void kill();
    virtual bool eat(Cell *);
	static unsigned int getCount();
};


#endif