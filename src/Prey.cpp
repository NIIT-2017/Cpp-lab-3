#include "Prey.h"

#include <iostream>
using namespace std;

unsigned int Prey::count = 0;


unsigned int Prey::getCount()
{
	return count;
}

Prey::Prey(Cell * c, Values *val) :Object(c)
{
	count++;
	name = 'f';
	liveTime =val->liveTime2;
	hunger = val->hunger2;
	cycle_r =val->cycle_r2;
}
Prey::~Prey()
{
	count--;
}

int Prey::getType()
{
	return tp;
}

int Prey::getObject(int type)
{
	if (type==1) return liveTime;
	if (type==2) return hunger;
	if (type==3) return cycle_r;
}

void Prey::setObject(int type, int value)
{
	if (type == 1) liveTime=value;
	if (type == 2) hunger = value;
}

void Prey::live()
{
	liveTime--;
	hunger--;
	tp = 3;
}