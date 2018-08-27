#include "Coral.h"

#include <iostream>
using namespace std;

unsigned int Coral::count = 0;

unsigned int Coral::getCount()
{
	return count;
}

Coral::Coral(Cell * c, Values *val) :Object(c)
{
	count++;
	name = '*';
	liveTime = val->liveTime1;
	cycle_r = val->cycle_r1;
}
Coral::~Coral()
{
	count--;
}

int Coral::getType()
{
	return tp;
}

int Coral::getObject(int type)
{
	if (type == 1) return liveTime;
	if (type == 2) return 1;
	if (type == 3) return cycle_r;
}

void Coral::setObject(int type, int value) {}

void Coral::live()
{
	liveTime--;
	tp = 2;
}