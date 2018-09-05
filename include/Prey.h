
#ifndef _PREY_H_
#define _PREY_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"


class Prey :public Object
{
	int tp;        // Тип
	int liveTime;  // Длина жизни
	int hunger;    // Голод
	int cycle_r;   // Цикл размножения
	static unsigned int count;

public:

	Prey(Cell * = nullptr, Values * = nullptr);
	~Prey();
	int getType();
	void setObject(int, int);
	int getObject(int);
	void live();
	static unsigned int getCount();
};

#endif