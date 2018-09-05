#pragma once
#include "Object.h"
#include "Common.h"

// Время жизни рыбы
extern size_t PREY_LIVING_TIME;

// Время размножения рыбы
extern size_t PREY_REPRODUCTION;

class Prey : public Object
{
protected:
	void reproduction();
	bool try_step();
	bool step(coord_t x, coord_t y);
	bool born_tray(coord_t x, coord_t y);
	unsigned int reproduction_time;
	unsigned int living_time;
	unsigned int reproduction_time_max;
	unsigned int living_time_max;
	virtual  Object * new_object(coord_t x, coord_t y, unsigned int rep_t, unsigned int liv_t);
public:
	Prey(Cell * c, Cell **cs, unsigned int rep_time = PREY_REPRODUCTION, unsigned int liv_time = PREY_LIVING_TIME, char signature = PREY_N,
		unsigned int rep_time_max = PREY_REPRODUCTION, unsigned int liv_time_max = PREY_LIVING_TIME);
	~Prey();
	void live();
};

