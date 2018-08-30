#ifndef _STONE_H_
#define _STONE_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"


class Stone :public Object
{

    static size_t Stonecount;

public:
    size_t &Stonecount2();
	explicit Stone(Cell * = nullptr);
	~Stone();
	void live();
    static size_t getCount();
    //int liveTime;
	char getName();
     unsigned int Stonecount3;//?
     //unsigned int num ;//?
     void SetParamLive(const int liveTime, const size_t breeding_cycle){};
     void SetParamLive (const int liveTime, const size_t breeding_cycle, const int HungryTime ) {};
	//char getName();
}; 

#endif
