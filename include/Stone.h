#ifndef _STONE_H_
#define _STONE_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"


class Stone :public Object
{
	int tp;        // “ип
	int liveTime;  // ƒлина жизни
	static unsigned int count;
	
public:
	
	Stone(Cell * = nullptr);
	~Stone();
	void live();
	void setObject(int, int);
	int getObject(int);
	int getType();

	static unsigned int getCount();
};

#endif