#include "Stone.h"

#include <iostream>
using namespace std;

unsigned int Stone::count = 0;

unsigned int Stone::getCount()
{
	return count;
}

Stone::Stone(Cell * c) :Object(c)
{	
	name = '#';
	count++;
	liveTime = 1;
}
Stone::~Stone()
{
	count--;
}

int Stone::getType()
{
return tp;
}

int Stone::getObject(int type)
{
	if (type == 1) return 1;
	if (type == 2) return 1;
}

void Stone::setObject(int type, int value) {}


void Stone::live()
{
	tp = 1;
}