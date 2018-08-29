#ifndef _STONE_H_
#define _STONE_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"

class Stone : public Object
{
protected:
	static unsigned int count;

public:
	Stone(Cell * = nullptr);
	~Stone();
	void live();
	void die();
	void born(Cell *);
	void kill();
	static unsigned int getCount();
};


#endif