#include "Predator.h"
#include "Object.h"
#include "Ocean.h"
#include "common.h"
#include <iostream>
using namespace std;
unsigned int Predator::count = 0;
unsigned int Predator::getCount()
{
	return count;
}
Predator::~Predator()
{
	count--;
}
char Predator::getName()
{
	return PREDATOR_N;
}
Predator::Predator(Cell * c) :Object(c)
{
	count++;
	Setting setting;
	std::string str;
	str = "Predator_Breeding_Cycle";
	this->breeding_cycle = setting.getFromFile(str);
	str = "Predator_live_Time";
	this->liveTime = setting.getFromFile(str);
	str = "Predator_Hungry_Time";
	this->HungryTime = setting.getFromFile(str);
}

void Predator::live()
{    
	this->liveTime--;
	this->HungryTime--;
	
	if (this->liveTime <= 0 || this->HungryTime == 0)
	{
		this->cell->killMe();
		
	}
	else {
		
		bool flag = true;
		
		if (breeding_cycle == 0)
		{
			Setting setting;
			std::string str = "Predator_Breeding_Cycle";
			this->breeding_cycle = setting.getFromFile(str);
		}
		breeding_cycle--;
		int adress_x = this->cell->get_x();
		int adress_y = this->cell->get_y();

		if (breeding_cycle == 0)
		{
			for (int i = adress_x - 1; i != adress_x + 2; i++)
			{
				if (flag)
				{
					for (int j = adress_y - 1; j != adress_y + 2; j++)
					{
						{
							if (flag)
							{
								if (this->cell->IsExists(i, j))
								{
									Cell* nextCell = this->cell->offset(i - adress_x, j - adress_y);
									
									if (this->cell->IsFree(nextCell) || (nextCell->HasObj(PREY_N)))
									{
										if (nextCell->HasObj(PREY_N))
										{
											nextCell->killMe();
											Setting setting;
											std::string str = "Predator_Hungry_Time";
											this->HungryTime = setting.getFromFile(str);

										}
										
										Object *born = new Predator(nextCell);
										
										nextCell->setObject(born);
										this->cell->getOcean()->addObject(born);
										flag = false;
										
									}
								}
							}
						}
					}
				}
				else break;
			}
			flag = false;
		}
		else 
		{
			
			for (int i = adress_x - 1; i != adress_x + 2; i++)
			{
				if (flag)
				{
					for (int j = adress_y - 1; j != adress_y + 2; j++) {
						{
							if (flag)
							{
								if (this->cell->IsExists(i, j))
								{
									Cell* nextCell = this->cell->offset(i - adress_x, j - adress_y);

									if (this->cell->IsFree(nextCell) || (nextCell->HasObj(PREY_N) || (nextCell->HasObj(CORAL_N))))
									{
										if (nextCell->HasObj(PREY_N))
										{
											nextCell->killMe();
											std::string str = "Predator_Hungry_Time";
											Setting setting;
											this->HungryTime = setting.getFromFile(str);
											Object *born = new Predator(nextCell);
											born->SetParamLive(this->liveTime, this->breeding_cycle, this->HungryTime);
											nextCell->setObject(born);
											this->cell->getOcean()->addObject(born);
											flag = false;
											this->cell->killMe();
										}
									}
								}
							}
						}
					}
				}
				else break;
			}
			flag = false;
		     }
	}
	
}