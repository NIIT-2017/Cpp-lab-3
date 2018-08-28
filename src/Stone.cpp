#include "Stone.h"
#include "Ocean.h"
unsigned int Stone::count = 0;

unsigned int Stone::getCount()
{
	return count;
}

ObjType Stone::getType()
{
	return ObjType::STONE;
}

char Stone::getName()
{
	return STONE_N;
}

Stone::Stone(Cell * c) :Object(c)
{
	count++;
	liveTime = cell->getOcean()->getGlobal().LIVE_TIME_STONE;
}
Stone::~Stone()
{
	count--;
}
void Stone::setLiveTime(int time)
{
	liveTime = time;
}
void Stone::live()
{
	liveTime--;
	if (liveTime == 0)
		cell->killMe();
}