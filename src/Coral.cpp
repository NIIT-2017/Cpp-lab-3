#include "Coral.h"
#include "Ocean.h"
#include <iostream>
#include <string>
#include "setting.h"

using namespace std;
size_t Coral::count = 0;
//char         Object::name = CORAL_N;


size_t Coral::getCount()
{
    return count;
}

Coral::Coral(Cell * c) :Object(c)
{
    count++;
    Setting seting;
    std::string str = "Coral_Breeding_Cycle";
    //size_t f=getParamFromFille(str);
    this->breeding_cycle = seting.getParamFromFille(str);

    //breeding_cycle = Coral_Breeding_Cycle;
}

Coral::~Coral()
{
    count--;
}

void Coral::live()
{
    breeding_cycle--;
    if (breeding_cycle == 0) {
        int adress_x = this->cell->get_x();
        int adress_y = this->cell->get_y();
        for (int i = adress_x - 1; i != adress_x + 2; i++) {
            for (int j = adress_y - 1; j != adress_y + 2; j++)
            {
                if (this->cell->IsExists(i,j))
                {
                    Cell* nextCell = this->cell->offset(i - adress_x, j - adress_y);
                    if (this->cell->CellIsFree(nextCell)) {
                        Object *born = new Coral(nextCell);
                        nextCell->setObject(born);
                        this->cell->getOcean()->addObject(born);
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


