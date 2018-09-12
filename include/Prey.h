#ifndef __PREY_H_
#define _PREY_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"


class Prey :public Object
{
        static size_t count;
		//static char  name;
	public:
		
        explicit Prey(Cell * = nullptr);
        ~Prey();
		void live();
        static size_t getCount();
		char getName();
        size_t breeding_cycle;
        int liveTime;
        //void addPrey();
        void SetParamLive(const int liveTime, const size_t breeding_cycle);
        //void SetParamLive (const int liveTime, const size_t breeding_cycle, const int HungryTime ) {};
		//bool canmove(int direction);
};

#endif
