#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"



class Cell;
class Object
{
protected:
	Cell *cell;
	char name;
	static unsigned int count;
public:
	
	Object(Cell * = nullptr);
	virtual ~Object();
	virtual void live() = 0; // жизнь объекта
	void setCell(Cell*);
	char getName();
	virtual int getObject(int)=0;
	virtual void setObject(int, int) = 0;
	virtual int getType() = 0;
	static unsigned int getCount();	
};

#endif