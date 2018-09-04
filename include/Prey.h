#pragma once
#include "common.h"
#include "Object.h"
#include "Cell.h"
#include <cstdlib>

class Prey : public Object
{
public:
	explicit Prey(Cell * = nullptr);
	~Prey();
	void live();
	static unsigned int getCount();
	char getName();
	void SetParamLive( int liveTime,  size_t breeding_cycle);
	void SetParamLive(const int liveTime, const size_t breeding_cycle, const int HungryTime) {};
protected:
	static unsigned int count;
	int liveTime;
	int breeding_cycle;
	int HungryTime;

};

