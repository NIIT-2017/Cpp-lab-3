#include "Prey.h"
#include "Object.h"
#include "Ocean.h"
#include <iostream>
#include "common.h"
using namespace std;
unsigned int Prey::count = 0;
void SetParamLive( int liveTime,  size_t breeding_cycle) {
liveTime = liveTime-1;
breeding_cycle = breeding_cycle - 1;
};
unsigned int Prey::getCount()
{
	return count;
}
char Prey::getName()
{
	return PREY_N;
}
Prey::~Prey()
{
	count--;
}
Prey::Prey(Cell * c) :Object(c)
{
	Setting setting;
	count++;
    std::string str = "Prey_Breeding_Cycle";
	str = "Predator_Breeding_Cycle";
	this->breeding_cycle = setting.getFromFile(str);
	str = "Predator_live_Time";
	this->liveTime = setting.getFromFile(str);
	

}

void Prey::live()
{
	this->liveTime--;
	if (liveTime <= 0)
	{
		this->cell->killMe();
	}
	else
	{
		
		bool flag = true;
		int adress_x = this->cell->get_x();
		int adress_y = this->cell->get_y();
		if (breeding_cycle == 0)
		{
			Setting setting;
			std::string str = "Prey_Breeding_Cycle";
			this->breeding_cycle = setting.getFromFile(str);
			int num = 0;
			while (flag && (num < 10))
			{
				int i1 = rand() % (3) - 1;
				int i2 = rand() % (3) - 1;
				while (((i1 == 0) && (i2 == 0)) && num < 10)
				{
					i1 = rand() % (3) - 1;
					i2 = rand() % (3) - 1;
					num++;
				}
				num++;
				int i = adress_x + i1;
				int j = adress_y + i2;
				{
					{
						{
							if (flag)
							{
								if (this->cell->IsExists(i, j))
								{
									Cell* nextCell = this->cell->offset(i - adress_x, j - adress_y);
									if (this->cell->IsFree(nextCell) || (nextCell->HasObj(CORAL_N)))
									{
										Object *born = new Prey(nextCell);
										nextCell->setObject(born);
										this->cell->getOcean()->addObject(born);
										flag = false;
									}
								}
							}
						}
					}
				}
			}
			flag = false;
		}
		else //move time
		{
			int num = 0;
			while (flag && (num < 9))
			{
				int i1 = rand() % (3) - 1;
				int i2 = rand() % (3) - 1;
				while (((i1 == 0) && (i2 == 0)) && num != 9)
				{
					i1 = rand() % (3) - 1;
					i2 = rand() % (3) - 1;
					num++;
				}
				num++;
				int i = adress_x + i1;
				int j = adress_y + i2;
				{
					{
						if (flag)
						{
							if (this->cell->IsExists(i, j))
							{
								Cell* nextCell = this->cell->offset(i - adress_x, j - adress_y);
								if (this->cell->IsFree(nextCell) || (nextCell->HasObj(CORAL_N)))
								{
									if (nextCell->HasObj(CORAL_N))
										nextCell->killMe();

									Prey *newPrey = new Prey(nextCell);
									newPrey->SetParamLive(this->liveTime, this->breeding_cycle);
									
									Object *born = newPrey;
									
									nextCell->setObject(born);
									this->cell->getOcean()->addObject(born);
									this->cell->killMe();
									flag = false;
								}
							}
						}
					}
				}
			}
		}
		flag = false;
	}
}
