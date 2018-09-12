#include "Cell.h"
#include "Ocean.h"

void Cell::init(Pair p, Ocean* oc)
{
	obj = nullptr;
	crd = p;
	ocean = oc;
}

Object* Cell::getObject() const
{
	return obj;
}

Ocean * Cell::getOcean() const
{
	return ocean;
}

void Cell::setObject(Object* c)
{
	obj = c;
}

void Cell::killMe()
{
	if (obj)
	{
		
		delete obj;
		obj = nullptr;
	}
}

coord_t Cell::getX()
{
	return crd.x;
}

coord_t Cell::getY()
{
	return crd.y;
}