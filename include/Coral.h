#ifndef _CORAL_H_
#define _CORAL_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"


class Coral :public Object
{
	int tp;        // “ип
	int liveTime;  // ƒлина жизни
	int cycle_r;   // ÷икл размножени¤
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