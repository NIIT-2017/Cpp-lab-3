#include "Predator.h"

unsigned int Predator::count = 0;

unsigned int Predator::getCount()
{
    return count;
}

Predator::Predator(Cell *c) : Object(c)
{
    type = ObjType::PREDATOR;
    name = g_data["Predator"]["name"].GetString()[0];
	lifeTime = g_data["Predator"]["lifeTime"].GetInt();
    timeBirth = g_data["Predator"]["timeBirth"].GetInt();
    feedCycle = g_data["Predator"]["feedCycle"].GetInt();
    lifeCycle = 0;
    eatCycle = feedCycle;
    isEat = false;
    count++;
}

Predator::~Predator()
{
    count--;
}

//жизнь хищника
//двигается один раз
void Predator::live()
{
    isReproduce = false;
    lifeCycle++;
    eatCycle--;
    lifeTime--;
    move();
    die();
}

//умирание хищника, записать его в список мертвецов
void Predator::die()
{
    if (lifeTime == 0 || eatCycle == 0)
        cell->setKill();
}

//рождение хищника, записать в список рождающихся
//рождается если перешла на клетку с другим хищником
//рождается каждый раз, после определенного возраста и если сыта
//n попыток на размножение в любую сторону
void Predator::born(Cell *tcell)
{
    if (lifeCycle >= timeBirth && isEat && !isReproduce && tcell->getObject() && tcell->getObject()->getType() == ObjType::PREDATOR && tcell->getObject()->getLifeTime() > 0)
    {
        size_t n = 10;
        for (size_t i = 0; i < n; i++)
        {
            Cell *tempCell = cell->getCell();
            if (tempCell != cell && !tempCell->getObject())
            {
                tempCell->setBorn(ObjType::PREDATOR);
                isReproduce = true;
            }
        }
    }
}

//движение хищника
//двигатся в свободную клетку, либо стоит, либо на место съеденой добычи
void Predator::move()
{
    Cell *tempCell = cell->getCell();
    if (tempCell != cell)
    {
        bool b = eat(tempCell);
        born(tempCell);
        if (!tempCell->getObject() || b)
        {
            tempCell->setObject(this);
            cell->setObject(nullptr);
            cell = tempCell;
        }
    }
}

//уничтожить хищника
void Predator::kill()
{
    cell->killMe(this);
}

//питание хищника
//если попадает на добычу, то съедает (добыча добавляется в список умерших)
bool Predator::eat(Cell *tempCell)
{
    if (tempCell->getObject() && tempCell->getObject()->getType() == ObjType::PREY)
    {
        isEat = true;
        eatCycle = feedCycle;
        tempCell->setKill();
        return true;
    }
    return false;
}