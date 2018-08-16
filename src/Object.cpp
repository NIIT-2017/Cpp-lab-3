#include "Object.h"
#include <cstdlib>

unsigned int Object::count = 0;

unsigned int Object::getCount()
{
	return count;
}

Object::Object(Cell *c) : cell(c)
{
	bisLive = false;
	count++;
}

Object::~Object()
{
	count--;
}

void Object::setCell(Cell *c)
{
	cell = c;
}

char Object::getName()
{
	return name;
}

ObjType Object::getType()
{
	return type;
}

void Object::setLive(bool b)
{
	bisLive = b;
}

bool Object::isLive()
{
	return bisLive;
}

unsigned int Object::getLifeTime()
{
    return lifeTime;
}