#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

class Cell;

class Object
{
protected:
	Cell *cell;
	char name;
	ObjType type;
	static unsigned int count;
	unsigned int lifeTime;
	bool bisLive;

public:
	Object(Cell * = nullptr);
	virtual ~Object();
	virtual void live() = 0;
	virtual void die() = 0;
	virtual void born(Cell *) = 0;
	virtual void kill() = 0;
	void setCell(Cell *);
	char getName();
	ObjType getType();
	unsigned int getLifeTime();
	static unsigned int getCount();
	void setLive(bool);
	bool isLive();
};

#endif
