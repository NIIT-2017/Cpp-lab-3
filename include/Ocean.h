#ifndef _OCEAN_H_
#define _OCEAN_H_


#include "common.h"
#include "Cell.h"
#include <list>
#include <map>
#include<string>


class Cell;
class Ocean
{
	
private:
	Cell **cells;
	//std::list<Object*> stuff;
	std::map<Pair, Object*> liveObject;
	Values global;
	bool read(const std::string &);
	int fill(const char*, int, int);
public:
	Ocean(const std::string &);
	~Ocean();
	void print() const;
	void addObjects(int);
	void addObjects(int, ObjType);
	void addObject(ObjType, Pair);
	void addObject(Object *, Pair);
	void updateObject(Object *, Pair);
	void removeObj(Object * o);
	Object * getObject(Pair) const;
	Cell * getCell(Pair) const;
	int run();
	int isEnd();
	Values getGlobal();
	unsigned int getSize();
};


#endif
