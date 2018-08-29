#include "Prey.h"

unsigned int Prey::count = 0;

unsigned int Prey::getCount()
{
	return count;
}

Prey::Prey(Cell *c) : Object(c)
{
    type = ObjType::PREY;
    name = g_data["Prey"]["name"].GetString()[0];
	lifeTime = g_data["Prey"]["lifeTime"].GetInt();
    timeBirth = g_data["Prey"]["timeBirth"].GetInt();
    lifeCycle = 0;
    isEat = false;
    count++;
}

Prey::~Prey()
{
	count--;
}

//жизнь добычи
//двигается один раз
void Prey::live()
{
    isReproduce = false;
    lifeCycle++;
    lifeTime--;
    move();
	die();
}

//умирание добычи, записать его в список мертвецов
void Prey::die()
{
    if (lifeTime == 0)
		cell->setKill();
}

//рождение добычи, записать в список рождающихся
//рождается если перешла на клетку с другой добычей
//рождается каждый раз, после определенного возраста
//n попыток на размножение в любую сторону, если сыта, то в три раза больше попыток
void Prey::born(Cell *tcell)
{
    if (lifeCycle >= timeBirth && !isReproduce
        && tcell->getObject() && tcell->getObject()->getType() == ObjType::PREY
        && tcell->getObject()->getLifeTime() > 0)
    {
        size_t n = 10;
        if (isEat) n *= 3;
        for(size_t i = 0; i < n; i++)
        {
            Cell *tempCell = cell->getCell();
            if (tempCell != cell && !tempCell->getObject())
            {
                tempCell->setBorn(ObjType::PREY);
                isReproduce = true;
            }
        }
    }
}

//движение добычи
//двигатся в свободную клетку, либо стоит, либо на место съеденого коралла
void Prey::move()
{
    Cell *tempCell = cell->getCell();
    if (tempCell != cell) {
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

//уничтожить добычу
void Prey::kill()
{
    cell->killMe(this);
}

//питание добычи
//если попадает на коралл, то сыт
//если кораллов больше, чем хищников, то коралл уничтожается (добавляется в список умерших)
//(условие баланса, чтобы все кораллы не были съедены)
bool Prey::eat(Cell *tempCell)
{
    if (tempCell->getObject() && tempCell->getObject()->getType() == ObjType::CORAL && !isEat)
    {
        isEat = true;
        if (Coral::getCount() > (Predator::getCount() + Prey::getCount()) / 10 || Predator::getCount() == 0)
        {
            tempCell->setKill();
            return true;
        }
    }
    return false;
}