#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "Cell.h"
#include <set>
#include <map>

class Ocean
{
private:
	size_t size_x;
	size_t size_y;
	unsigned int count;
	unsigned int maxCount;
	Cell **cells;
	std::set<Object *> stuff;
	std::set<Object *> stuffDie;
	std::map<Cell *, ObjType> stuffBorn;

	Object* (*getObjType(ObjType)) (Cell *);
	void addObject(Pair, Object* (*) (Cell *));
	void addObjects(int);
	void addObjects(int, ObjType);
	bool isEnd();

public:
	Ocean(const char *);
	~Ocean();
	void addObjects(Pair, ObjType);
	void delObject(Object *);
	Cell* getCell(Pair);
	void print() const;
	void run();
	void setDelObject(Object *);
	void setBornObject(Cell *, ObjType);
};


#endif