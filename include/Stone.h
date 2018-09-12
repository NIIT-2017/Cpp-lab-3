#pragma once

#include "Cell.h"
#include "Object.h"
class Stone : public Object
{
private:

public:
	Stone(Cell * c = nullptr, Cell **cs = nullptr);
	~Stone();
	void live();
};

