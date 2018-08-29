#include "Prey.h"
#include "Ocean.h"
#include <random>
#include <ctime>
#include <algorithm>

unsigned int Prey::count = 0;

Prey::Prey(Cell * c) : Object(c)
{
	count++;
	liveTime = cell->getOcean()->getGlobal().LIVE_TIME_PREY;
	liveBreeding = cell->getOcean()->getGlobal().BREED_TIME_PREY;
}

Prey::~Prey()
{
	count--;
}

void Prey::live()
{
	move();
	breeding();
	liveTime--;
	if (liveTime == 0)
		cell->killMe();
}


unsigned int Prey::getCount()
{
	return count;
}

void Prey::move()
{
	enum class Direction { UP_LEFT, UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT };
	//srand(time(nullptr));
	Ocean * o = this->cell->getOcean();
	Direction k; 
	Pair crd = this->cell->getPair();
	Pair old_crd = crd;
	unsigned int N = cell->getOcean()->getGlobal().N;
	unsigned int M = cell->getOcean()->getGlobal().M;
	do
	{
		k = static_cast<Direction>(rand() % 8);
		switch (k)
		{
		case Direction::UP_LEFT:
			if (Clamp(crd.x - 1, 0, M-1) && Clamp(crd.y + 1, 0, N-1))
			{
				crd.x -= 1;
				crd.y += 1;
			}
			break;
		case Direction::UP:
			if (Clamp(crd.y + 1, 0, N-1))
			{
				crd.y += 1;
			}
			break;
		case Direction::UP_RIGHT:
			if (Clamp(crd.x + 1, 0, M - 1) && Clamp(crd.y + 1, 0, N - 1))
			{
				crd.x += 1;
				crd.y += 1;
			}
			break;
		case Direction::RIGHT:
			if (Clamp(crd.x + 1, 0, M - 1))
			{
				crd.x += 1;
			}
			break;
		case Direction::DOWN_RIGHT:
			if (Clamp(crd.x + 1, 0, M - 1) && Clamp(crd.y - 1, 0, N - 1))
			{
				crd.x += 1;
				crd.y -= 1;
			}
			break;
		case Direction::DOWN:
			if (Clamp(crd.y - 1, 0, N - 1))
			{
				crd.y -= 1;
			}
			break;
		case Direction::DOWN_LEFT:
			if (Clamp(crd.x - 1, 0, M - 1) && Clamp(crd.y - 1, 0, N - 1))
			{
				crd.x -= 1;
				crd.y -= 1;
			}
			break;
		case Direction::LEFT:
			if (Clamp(crd.x - 1, 0, M - 1))
			{
				crd.x -= 1;
			}
			break;
		}
	}
	while (o->getObject(crd));
	Object * o1 = o->getObject(old_crd);
	Object * o2 = o->getObject(crd);
	o->updateObject(o1, crd);
	o->updateObject(o2, old_crd);

}


void Prey::breeding()
{
	if (liveBreeding == 0)
	{
		unsigned int x = this->cell->getPair().x;
		unsigned int y = this->cell->getPair().y;
		Ocean * o = this->cell->getOcean();
		bool breed = false;
		unsigned int N = cell->getOcean()->getGlobal().N;
		unsigned int M = cell->getOcean()->getGlobal().M;
		for (unsigned int i = x - 1; i <= x + 1; i++)
		{
			if (!Clamp(i, 0, M-1))
				continue;
			for (unsigned int j = y - 1; j <= y + 1; j++)
			{
				if (!Clamp(j, 0, N-1))
					continue;
				else if (!o->getObject(Pair{ i, j }))
				{
					Prey *pr = new Prey(o->getCell(Pair{ i,j }));
					o->addObject(pr, Pair{ i, j });
					breed = true;
					break;
				}
			}
			if (breed)
				break;
		}
		liveBreeding = cell->getOcean()->getGlobal().BREED_TIME_PREY;
	}
	liveBreeding--;
}

ObjType Prey::getType()
{
	return ObjType::PREY;
}

char Prey::getName()
{
	return PREY_N;
}
