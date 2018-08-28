#include "Coral.h"
#include "Ocean.h"
unsigned int Coral::count = 0;


Coral::Coral(Cell * c) : Stone(c)
{
	Stone::count--;
	count++;
	liveBreeding = cell->getOcean()->getGlobal().BREED_TIME_CORAL;
	liveTime = cell->getOcean()->getGlobal().LIVE_TIME_CORAL;
}

Coral::~Coral()
{
	Stone::count++;
	count--;
}

void Coral::breed()
{
	if (liveBreeding == 0 && rel == relationship::PARENT)
	{
		num++;
		size_t x = this->cell->getPair().x;
		size_t y = this->cell->getPair().y;
		Ocean * o = this->cell->getOcean();
		for (int i = x - num; i <= x + num; i++)
		{
			if (!Clamp(i, 0, cell->getOcean()->getGlobal().M - 1))
				continue;
			else if (!o->getObject(Pair{ (coord_t)i, y }))
			{
				Coral * cr = new Coral(o->getCell(Pair{ (coord_t)i,y }));
				cr->setRelationship(relationship::CHILDREN);
				cr->setLiveTime(this->liveTime - 1); // так как потом время у родителя уменьшается на 1, а у детей нет
				o->addObject(cr, Pair{ (coord_t)i, y });
			}
		}
		for (int j = y - num; j <= y + num; j++)
		{
			if (!Clamp(j, 0, cell->getOcean()->getGlobal().N - 1))
				continue;
			else if (!o->getObject(Pair{ x, (coord_t)j }))
			{
				Coral * cr = new Coral(o->getCell(Pair{ x,(coord_t)j }));
				cr->setRelationship(relationship::CHILDREN);
				cr->setLiveTime(this->liveTime - 1);
				o->addObject(cr, Pair{ x, (coord_t)j });
			}
		}
		liveBreeding = cell->getOcean()->getGlobal().BREED_TIME_CORAL;
	}
	else
	{
		liveBreeding--;
	}
}


void Coral::live()
{
	breed();
	liveTime--;
	if (liveTime == 0)
		cell->killMe();
}

unsigned int Coral::getCount()
{
	return count;
}

void Coral::setRelationship(relationship rel)
{
	this->rel = rel;
}

ObjType Coral::getType()
{
	return ObjType::CORAL;
}

char Coral::getName()
{
	return CORAL_N;;
}




