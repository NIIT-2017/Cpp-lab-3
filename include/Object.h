#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum ObjType {STONE,CORAL,PREY,PREDATOR};

class Cell;
class Object
{
protected:
	Cell *cell;
	static char name;
	static unsigned int count;
public:

	Object(Cell * = nullptr);
	virtual ~Object();
	virtual void live() = 0; 
	void setCell(Cell*);
	virtual char getName();
	static unsigned int getCount();
	virtual void SetParamLive(const int liveTime, const size_t breeding_cycle) = 0;
	virtual void SetParamLive(const int liveTime, const size_t breeding_cycle, const int HungryTime) = 0;

};

#endif