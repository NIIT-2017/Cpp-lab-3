#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "Object.h"
#include "Stone.h"
#include "Coral.h"
#include "Prey.h"
#include "Predator.h"

class Ocean;

class Cell
{
	friend Ocean;
private:
	Pair crd;
	Object *obj;
	Ocean *ocean;

public:
	explicit Cell(Pair = { 0, 0 }, Ocean* = nullptr);
	void init(Pair, Ocean *);
	void bornObject(ObjType);
	Cell* getCell();
	Object* getObject() const;
	void setObject(Object *);
	void killMe(Object *);
	void setKill();
	void setBorn(ObjType);
};


#endif