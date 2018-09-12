#pragma once
#include "Cell.h"
#include "Object.h"

class Coral : public Object
{
private:
	unsigned int reproduction_time;
public:
	Coral(Cell * c = nullptr, Cell **cs = nullptr);
	~Coral();
	void live();
};

