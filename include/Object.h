#ifndef _OBJECT_H_
#define _OBJECT_H_
#include "common.h"
//#include <cstring>
#include <string>

class Cell;
class Object
{
protected:
	Cell *cell;
    static char name;//УБРАТЬ
    static size_t count;
public:
	explicit Object(Cell * = nullptr);
	//static char name;//УБРАТЬ


	void setCell(Cell*);
	//static char getName();
    static size_t getCount();

    //virtual public:
    virtual char getName() = 0;
    //virtual void SetParamLive (const int liveTime, const size_t breeding_cycle) = 0;
    //virtual void SetParamLive (const int liveTime, const size_t breeding_cycle, const int HungryTime ) = 0;
    void SetParamLive (const int liveTime, const size_t breeding_cycle, const int HungryTime );
    virtual void live() = 0; // жизнь объекта
    virtual ~Object();
    //bool CanMove(int direction);//?
};


#endif
