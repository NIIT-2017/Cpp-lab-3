#ifndef PREDATOR_H
#define PREDATOR_H
#include "common.h"
#include "Object.h"
#include "Cell.h"


class Predator :public Object
{
        static size_t count;
        //static char  name;
    public:

        explicit Predator(Cell * = nullptr);
        ~Predator();
        void live();
        static size_t getCount();
        char getName();
        size_t breeding_cycle;
        int liveTime;
        int HungryTime;
        void SetParamLive(const int liveTime, const size_t breeding_cycle,const int HungryTime);
        //void SetParamLive (const int liveTime, const size_t breeding_cycle) {};
        //bool canmove(int direction);
};

#endif // PREDATOR_H
