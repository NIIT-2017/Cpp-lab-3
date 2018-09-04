#pragma once
#include "common.h"
#include "Object.h"
#include "Cell.h"

class Predator : public Object
{
	int liveTime;
	int breeding_cycle;
	int HungryTime;
	static unsigned int count;
	
public:
	explicit Predator(Cell * = nullptr);
	~Predator();
	char getName();
	void live();
	static unsigned int getCount();
	void SetParamLive(const int liveTime, const size_t breeding_cycle) {};
	void SetParamLive(const int liveTime, const size_t breeding_cycle, const int HungryTime) {};
};
