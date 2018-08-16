#include "Coral.h"

unsigned int Coral::count = 0;

unsigned int Coral::getCount()
{
	return count;
}

Coral::Coral(Cell *c) : Object(c)
{
    type = ObjType::CORAL;
    name = g_data["Coral"]["name"].GetString()[0];
	lifeTime = g_data["Coral"]["lifeTime"].GetInt();
    timeBirth = g_data["Coral"]["timeBirth"].GetInt();
    lifeCycle = 0;
    count++;
}

Coral::~Coral()
{
	count--;
}

//жизнь коралла
void Coral::live()
{
    lifeCycle++;
    lifeTime--;
    born(nullptr);
	die();
}

//умирание коралл, записать его в список мертвецов
//вместо коралла образуется риф, то есть камень
void Coral::die()
{
    if (lifeTime == 0)
    {
        cell->setKill();
        cell->setBorn(ObjType::STONE);
    }
}

//рождение коралла, записать в список рождающихся
//рождается раз за цикл
// n попыток на рождение
//размножается в любую одну сторону, уничтожая все живое
void Coral::born(Cell *tcell)
{
    if (lifeCycle == timeBirth)
    {
        size_t n = 2;
        for(size_t i = 0; i < n; i++)
        {
            Cell *tempCell = cell->getCell();
            if (tempCell != cell)
            {
                if (tempCell->getObject() && tempCell->getObject()->getType() != ObjType::STONE
                    && tempCell->getObject()->getType() != ObjType::CORAL)
                {
                    tempCell->setKill();
                    tempCell->setBorn(ObjType::CORAL);
                }
            }
            if (!tempCell->getObject())
                tempCell->setBorn(ObjType::CORAL);
        }
        lifeCycle = 0;
    }
}

//уничтожить коралл
void Coral::kill()
{
    cell->killMe(this);
}