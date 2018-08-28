#ifndef _CORAL_H_
#define _CORAL_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"


class Coral :public Object
{
	int tp;        // тип
	int liveTime;  // длина жизни
	int cycle_r;   // цикл размножения
	static unsigned int count;
	
public:
	
	Coral(Cell * = nullptr, Values * = nullptr);
	~Coral();
	int getType();
	void setObject(int, int);
	int getObject(int);
	void live();
	static unsigned int getCount();
};

#endif