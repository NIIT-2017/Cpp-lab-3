#include "Coral.h"
#include "Ocean.h"
#include "common.h"
#include <iostream>

using namespace std;

unsigned int Coral::count = 0;
unsigned int Coral::getCount()
{
	return count;
}
Coral::Coral(Cell * c) :Object(c)
{
	count++;
	Setting setting;
	string str = "Coral_Breeding_Cycle";
	
	breeding_cycle = setting.getFromFile(str);
}
Coral ::~Coral()
{
	count--;
}
void Coral::live()
{
	breeding_cycle--;
	if (breeding_cycle == 0) {
		int adress_x = cell->get_x();
		int adress_y = cell->get_y();
		for (int i = adress_x - 1; i < adress_x + 2; i++) {
			for (int j = adress_y - 1; j < adress_y + 2; j++)
			{
				if (cell->IsExists(i, j))
				{
					Cell* nextCell = cell->offset(i - adress_x, j - adress_y);
					if (cell->IsFree(nextCell)) {
						Object *born = new Coral(nextCell);
						nextCell->setObject(born);
						cell->getOcean()->addObject(born);
					}
				}
			}
		}
	}
    
}

char Coral::getName()
{
	return CORAL_N;
}

