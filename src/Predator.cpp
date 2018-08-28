#include "Predator.h"
#include "Ocean.h"
#include <random>
#include <ctime>
#include <algorithm>

unsigned int Predator::count = 0;

Predator::Predator(Cell * c) : Prey(c)
{
	Prey::count--;
	count++;
	liveTime = cell->getOcean()->getGlobal().LIVE_TIME_PREDATOR;
	liveBreeding = cell->getOcean()->getGlobal().BREED_TIME_PREDATOR;
	timeFood = cell->getOcean()->getGlobal().FOOD_TIME_PREDATOR;
}

Predator::~Predator()
{
	Prey::count++;
	count--;
}

void Predator::live()
{
	if (food())
	{
		move();
		breeding();
		liveTime--;
		if (liveTime == 0)
			cell->killMe();
	}
	}

unsigned int Predator::getCount()
{
	return count;
}

char Predator::getName()
{
	return PREDATOR_N;
}

void Predator::breeding()
{
	if (liveBreeding == 0)
	{
		size_t x = this->cell->getPair().x;
		size_t y = this->cell->getPair().y;
		Ocean * o = this->cell->getOcean();
		bool breed = false;
		size_t M = cell->getOcean()->getGlobal().M;
		size_t N = cell->getOcean()->getGlobal().N;
		for (size_t i = x - 1; i <= x + 1; i++)
		{
			if (!Clamp(i, 0, M - 1))
				continue;
			for (size_t j = y - 1; j <= y + 1; j++)
			{
				if (!Clamp(j, 0, N - 1))
					continue;
				else if (!o->getObject(Pair{ i, j }))
				{
					Predator *pr = new Predator(o->getCell(Pair{ i,j }));
					o->addObject(pr, Pair{ i, j });
					breed = true;
					break;
				}
			}
			if (breed)
				break;
		}
		liveBreeding = cell->getOcean()->getGlobal().BREED_TIME_PREDATOR;
	}
	liveBreeding--;
}

bool Predator::food()
{
	int x = this->cell->getPair().x;
	int y = this->cell->getPair().y;
	Ocean * o = this->cell->getOcean();
	bool food = false;
	size_t N = cell->getOcean()->getGlobal().N;
	size_t M = cell->getOcean()->getGlobal().M;
 	if (timeFood < cell->getOcean()->getGlobal().FOOD_TIME_PREDATOR / 2)
	{
		if (timeFood == 0)
		{
			cell->killMe();
			return false;
		}
		for (int i = x - 1; i <= x + 1; i++)
		{
			if (!Clamp(i, 0, M-1))
				continue;
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (!Clamp(j, 0, N-1))
					continue;
				else if (o->getObject(Pair{ (coord_t)i, (coord_t)j }) != nullptr)
				{
					if (o->getObject(Pair{ (coord_t)i, (coord_t)j })->getType() == ObjType::PREY)
					{
						o->getObject(Pair{ (coord_t)i, (coord_t)j })->getCell()->killMe();
						food = true;
						break;
					}
				}
			}
			if (food)
			{
				timeFood = cell->getOcean()->getGlobal().FOOD_TIME_PREDATOR;
				break;
			}
		}
	}
	if (!food)
		timeFood--;
	return true;
}

ObjType Predator::getType()
{
	return ObjType::PREDATOR;
}
