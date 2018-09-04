#pragma once
#include "common.h"
#include "Object.h"
#include "Cell.h"
class Coral : public Object
{
	size_t breeding_cycle;
	
public:
	explicit Coral(Cell * = nullptr);
	void SetParamLive(const int liveTime, const size_t breeding_cycle) {};
	void SetParamLive(const int liveTime, const size_t breeding_cycle, const int HungryTime) {};
	~Coral();
	void live();
	static unsigned int getCount();
	char getName();
	
};
