#include "Cell.h"
#include "Ocean.h"
Cell::~Cell()
{
	delete obj;
}
void Cell::init(Pair p, Ocean* oc)
{
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
void Cell::setObject(Object *obj)
{
	this->obj = obj;
}

Pair Cell::getPair() const
{
	return crd;
}

void Cell::setPair(Pair crd)
{
	this->crd = crd;
}

void Cell::killMe()
{
	if (obj)
	{
		if (!ocean)
		{
			delete obj;
			obj = nullptr;
		}
		else
			this->ocean->removeObj(obj);
	}
}

