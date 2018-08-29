#include "Object.h"
#include <cstdlib>

unsigned int Object::count = 0;
unsigned int Object::getCount()
{
	return count;
}


Object::Object(Cell * c) :cell(c)
{
	//name = rand() % ('Z' - 'A' + 1) + 'A';
	count++;
}

Object::~Object()
{
	count--;
}

void Object::setCell(Cell* c)
{
	cell = c;
}



Cell * Object::getCell() const
{
	return cell;
}
