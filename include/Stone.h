#ifndef _STONE_H_
#define _STONE_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"


class Stone :public Object
{
	static unsigned int count;
public:
	explicit Stone(Cell * = nullptr);
	~Stone();
	void live();
	static unsigned int getCount();
	char getName();
	void SetParamLive(const int liveTime, const size_t breeding_cycle) {};
	void SetParamLive(const int liveTime, const size_t breeding_cycle, const int HungryTime) {};
};

#endif