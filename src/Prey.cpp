#include "Prey.h"
#include "Ocean.h"

extern size_t Y_MAX;	// y
extern size_t X_MAX;	// x


Prey::Prey(Cell * c, Cell **cs, unsigned int rep_time, unsigned int liv_time, char signature,
			unsigned int rep_time_max, unsigned int liv_time_max )
	: Object(c, cs, signature)
{
	must_die = false;
	living_time = liv_time;
	reproduction_time = rep_time;
	living_time_max = liv_time_max;
	reproduction_time_max = rep_time_max;
}

Prey::~Prey()
{

}

void Prey::live()
{
	if (must_die == true)
	{
		cell->getOcean()->deleteObject(cell, this);
		delete this;
		return;
	}
	living_time--;
	if (living_time == 0)
	{
		cell->getOcean()->deleteObject(cell, this);
		cell->killMe();
		return;
	}
	reproduction_time--;
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

// Функция для размножения
void Prey::reproduction()
{
	coord_t x = cell->getX();
	coord_t y = cell->getY();
	bool reproductuon_ready = false;
	size_t reproduction_step = rand() % 4;
	char cnt = 0;
	while (reproductuon_ready == false)
	{
		switch (reproduction_step)
		{
		case 0:
			reproductuon_ready = born_tray(x - 1, y);
			break;
		case 1:
			reproductuon_ready = born_tray(x + 1, y);
			break;
		case 2:
			reproductuon_ready = born_tray(x, y + 1);
			break;
		case 3:
			reproductuon_ready = born_tray(x, y - 1);
			break;
		}
		reproduction_step = reproduction_step + 1;
		if (reproduction_step >= 4)
			reproduction_step = 0;
		cnt = cnt + 1;
		if (cnt >= 4)
			break;
	}
}

// Попытка шагнуть
bool  Prey::try_step()
{
	coord_t x = cell->getX();
	coord_t y = cell->getY();
	bool next_step_ready = false;
	size_t next_step = rand() % 4;
	char cnt = 0;
	while (next_step_ready == false)
	{
		switch (next_step)
		{
		case 0:
			next_step_ready = step(x - 1, y);
			break;
		case 1:
			next_step_ready = step(x + 1, y);
			break;
		case 2:
			next_step_ready = step(x, y + 1);
			break;
		case 3:
			next_step_ready = step(x, y - 1);
			break;
		}
		next_step = next_step + 1;
		if (next_step >= 4)
			next_step = 0;
		cnt = cnt + 1;
		if (cnt >= 4)
			break;
	}
	return next_step_ready;
}


// Функция шага рыбы. Возвращает true если удалось сделать шаг в новую ячейку
bool Prey::step(coord_t x, coord_t y)
{
	if(x >= X_MAX || y >= Y_MAX)
		return false;
	if (x + 1 < 1 || y + 1 < 1)
		return false;
	if (cells[y][x].getObject())
		return false;
	Object *born = new_object(x, y, reproduction_time, living_time);
	cells[y][x].getOcean()->changeObject(born->cell, this, born);
	return true;
}

// Попытка размножения
bool Prey::born_tray(coord_t x, coord_t y)
{
	if (x >= X_MAX || y >= Y_MAX)
		return false;
	if (x + 1 < 1 || y + 1 < 1)
		return false;
	if (cells[y][x].getObject())
		return false;
	Object *born = new_object(x, y, reproduction_time_max, living_time_max);
	cells[y][x].getOcean()->addObject(born->cell, born);
	return true;
}

// Создание норвого объекта
Object * Prey::new_object(coord_t x, coord_t y, unsigned int reproduction_t, unsigned int living_t)
{
	Prey * born = new Prey(&cells[y][x], this->cells, reproduction_t, living_t);
	return born;
}


