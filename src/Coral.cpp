#include "Coral.h"
#include "Ocean.h"

extern size_t CORAL_REPRODUCTION_TIME;

extern size_t Y_MAX;	// y
extern size_t X_MAX;	// x

Coral::Coral(Cell * c, Cell **cs) : Object(c, cs, CORAL_N)
{

	reproduction_time = CORAL_REPRODUCTION_TIME;
}

Coral::~Coral()
{

}

void Coral::live()
{
	reproduction_time--;
	if (reproduction_time == 0)
	{
		reproduction_time = CORAL_REPRODUCTION_TIME;
		coord_t x = cell->getX();
		coord_t y = cell->getY();

		if ((x + 1) < X_MAX)
		{
			if (!cells[y][x + 1].getObject())
			{
				Coral *born = new Coral(&cells[y][x + 1], this->cells);
				cells[y][x + 1].getOcean()->addObject(born->cell, born);
			}
		}

		if (x >= 1)
		{
			if (!cells[y][x - 1].getObject())
			{
				Coral *born = new Coral(&cells[y][x - 1], this->cells);
				cells[y][x - 1].getOcean()->addObject(born->cell, born);
			}
		}

		if ((y + 1) < Y_MAX)
		{
			if (!cells[y + 1][x].getObject())
			{
				Coral *born = new Coral(&cells[y + 1][x], this->cells);
				cells[y + 1][x].getOcean()->addObject(born->cell, born);
			}
		}

		if (y >= 1)
		{
			if (!cells[y - 1][x].getObject())
			{
				Coral *born = new Coral(&cells[y - 1][x], this->cells);
				cells[y - 1][x].getOcean()->addObject(born->cell, born);
			}
		}

	}
}
