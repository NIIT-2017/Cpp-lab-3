#include "Stone.h"

unsigned int Stone::count = 0;

unsigned int Stone::getCount()
{
	return count;
}

Stone::Stone(Cell *c) : Object(c)
{
	type = ObjType::STONE;
	name = g_data["Stone"]["name"].GetString()[0];
	lifeTime = g_data["Stone"]["lifeTime"].GetInt();
	count++;
}

Stone::~Stone()
{
	count--;
}

//жизнь камня
void Stone::live()
{
	lifeTime--;
	die();
}

//умирание камня, записать его в список мертвецов
//море его сточило
void Stone::die()
{
	if (lifeTime == 0)
		cell->setKill();
}

void Stone::born(Cell *tcell) {}

//уничтожить камень
void Stone::kill()
{
	cell->killMe(this);
}