#include "Predator.h"

#include <iostream>
using namespace std;

unsigned int Predator::count = 0;

unsigned int Predator::getCount()
{
	return count;
}

Predator::Predator(Cell * c, Values *val) :Object(c)
{
	count++;
	name = 'S';
	liveTime = val->liveTime3;
	hunger = val->hunger3;
	cycle_r = val->cycle_r3;
}
Predator::~Predator()
{
	count--;
}

int Predator::getType()
{
	return tp;
}

int Predator::getObject(int type)
{
	if (type == 1) return liveTime;
	if (type == 2) return hunger;
	if (type == 3) return cycle_r;
}

void Predator::setObject(int type, int value)
{
	if (type == 1) liveTime = value;
	if (type == 2) hunger = value;
}

void Predator::live()
{
	liveTime--;
	hunger--;
	tp = 4;
}