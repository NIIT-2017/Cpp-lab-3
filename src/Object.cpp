
#include "Object.h"
#include <ctime>
#include <stdlib.h>

unsigned int Object::count_object = 0;
unsigned int Object::count_stone = 0;
unsigned int Object::count_coral = 0;
unsigned int Object::count_prey = 0;
unsigned int Object::count_predactor = 0;

Object::Object(Cell * c, Cell **cs, char n) : cell(c), cells(cs), name(n)
{
	count_object++;
	if (name == STONE_N)
		count_stone++;
	else if (name == CORAL_N)
		count_coral++;
	else if (name == PREY_N)
		count_prey++;
	else if (name == PREDATOR_N)
		count_predactor++;
	//name = rand() % ('Z' - 'A' + 1) + 'A';
}


void Object::setCell(Cell * c)
{
	cell = c;
}

char Object::getName()
{
	return name;
}

Object::~Object()
{
	count_object--;
	if (name == STONE_N)
		count_stone--;
	else if (name == CORAL_N)
		count_coral--;
	else if (name == PREY_N)
		count_prey--;
	else if (name == PREDATOR_N)
		count_predactor--;
}

// Устанавливаем признак того что объект должен умереть
void  Object::set_must_die()
{
	must_die = true;
	return;
}

bool Object::get_must_die()
{
	return must_die;
}

unsigned int Object::getCountObject()
{
	return count_object;
}

unsigned int  Object::getCountStone()
{
	return count_stone;
}
unsigned int  Object::getCountCoral()
{
	return count_coral;
}
unsigned int  Object::getCountPrey()
{
	return count_prey;
}
unsigned int  Object::getCountPredator()
{
	return count_predactor;
}
