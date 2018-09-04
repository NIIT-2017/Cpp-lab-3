#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "Object.h"


class Ocean;

class Cell
{
	friend Ocean;
private:
	Pair crd;
	Object *obj;
	Ocean *ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		crd(p),
		obj(nullptr),
		ocean(oc) {}
	void init(Pair p, Ocean* oc);
	Object* getObject() const;
	void setObject(Object*);
	void killMe();
	bool IsExists(const int x, const int y);
	size_t get_x();
	size_t get_y();
	Cell* offset(const int x, const int y);
	Ocean* getOcean();
	bool IsFree(Cell*  cell);
	bool HasObj(const char NameObj);
	void move(Cell  * c1, Cell  * c2);
};



#endif