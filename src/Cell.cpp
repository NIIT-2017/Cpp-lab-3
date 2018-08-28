#include "Cell.h"
#include <iostream>
using namespace std;

void Cell::init(Pair p, Ocean* oc)
{
	crd = p;
	ocean = oc;
}
Object* Cell::getObject() const
{
	return obj;
}
void Cell::setObject(Object *obj)
{
	this->obj = obj;
}

void Cell::killMe()
{
	if (obj)
	{   
		delete obj;
		obj = nullptr;
	}
}
