#ifndef _STONE_H_
#define _STONE_H_

#include "Object.h"
#include "Cell.h"



class Stone :public Object
{
protected:
	static unsigned int count;
	int liveTime;
public:
	Stone(Cell * = nullptr);
	~Stone();
	void setLiveTime(int);
	void live();
	static unsigned int getCount();
	ObjType getType();
	char getName();
};

#endif