#pragma once
#include "Object.h"
#include "Prey.h"
#include "Ocean.h"

extern size_t PREDATOR_LIVING_TIME;
extern size_t PREDATOR_REPRODUCTION;

class Predator : public Prey
{
private:
	Object * new_object(coord_t x, coord_t y, unsigned int reproduction_t, unsigned int living_t);
	bool try_eat();
	bool eat(coord_t x, coord_t y);
public:
	Predator(Cell * c, Cell **cs, unsigned int rep_time = PREDATOR_REPRODUCTION, 
			unsigned int liv_time = PREDATOR_LIVING_TIME, char signature = PREDATOR_N, 
				unsigned int rep_time_max= PREDATOR_REPRODUCTION, unsigned int liv_time_max = PREDATOR_LIVING_TIME);
	~Predator();
	void live();
};

