#include "Predator.h"

extern size_t Y_MAX;	// y
extern size_t X_MAX;	// x

extern size_t PREDATOR_LIVING_TIME;
extern size_t PREDATOR_REPRODUCTION;

Predator::Predator(Cell * c, Cell **cs, unsigned int rep_time, unsigned int liv_time, char signature,
	unsigned int rep_time_max, unsigned int liv_time_max)
	:Prey(c, cs, rep_time, liv_time, signature, rep_time_max, liv_time_max)
{

}


Predator::~Predator()
{
}

void Predator::live()
{	
	reproduction_time--;
	living_time--;
	bool eat_ready = try_eat();
	if (eat_ready == true)
	{
		cell->killMe();
		return;
	}
	if (living_time == 0)
	{
		cell->getOcean()->deleteObject(cell, this);
		cell->killMe();
		return;
	}
	if (reproduction_time == 0)
	{
		reproduction_time = PREY_REPRODUCTION;
		reproduction();
	}
	bool next_step_ready = try_step();
	if (next_step_ready == true)
	{
		cell->killMe();
	}
}

// Создание норвого объекта
Object * Predator::new_object(coord_t x, coord_t y, unsigned int reproduction_t, unsigned int living_t)
{
	Predator * born = new Predator(&cells[y][x], this->cells, reproduction_t, living_t);
	return born;
}

// Попытка съесть рыбу
bool Predator::try_eat() 
{
	bool try_eat_bool = false;

	coord_t x = cell->getX();
	coord_t y = cell->getY();
	size_t eat_step = rand() % 4;
	char cnt = 0;
	while (try_eat_bool == false)
	{
		switch (eat_step)
		{
		case 0:
			try_eat_bool = eat(x - 1, y);
			break;
		case 1:
			try_eat_bool = eat(x + 1, y);
			break;
		case 2:
			try_eat_bool = eat(x, y + 1);
			break;
		case 3:
			try_eat_bool = eat(x, y - 1);
			break;
		}
		eat_step = eat_step + 1;
		if (eat_step >= 4)
			eat_step = 0;
		cnt = cnt + 1;
		if (cnt >= 4)
			break;
	}
	return try_eat_bool;
}


bool Predator::eat(coord_t x, coord_t y)
{
	if (x >= X_MAX || y >= Y_MAX)
		return false;
	if (x + 1 < 1 || y + 1 < 1)
		return false;
	if (!cells[y][x].getObject())
		return false;
	if (cells[y][x].getObject()->getName() == PREY_N && cells[y][x].getObject()->get_must_die() == false)
	{
		cells[y][x].getObject()->set_must_die();
		if (reproduction_time == 0)
			reproduction_time = 1;
		Object *born = Predator::new_object(x, y, reproduction_time, PREDATOR_LIVING_TIME);
		this->cell->getOcean()->replaseObject(born->cell, born);
		this->cell->getOcean()->deleteObject(this->cell, this);
		return true;
	}
	return false;
}
