#ifndef _CORAL_H_
#define _CORAL_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"


class Coral :public Object
{
        static size_t count;
		//static char  name;
	public:
		
		explicit Coral(Cell * = nullptr);
		~Coral();
		void live();
        static size_t getCount();
		char getName();
        size_t breeding_cycle;
        void SetParamLive(int liveTime, size_t breeding_cycle){};
        void SetParamLive (int liveTime, size_t breeding_cycle, int HungryTime ){};


		//bool canmove(int direction);
};

#endif
