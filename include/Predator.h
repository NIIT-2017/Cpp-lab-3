
#ifndef _PREDATOR_H_
#define _PREDATOR_H_

#include "common.h"
#include "Object.h"
#include "Cell.h"


class Predator :public Object
{
	int tp;        // ���
	int liveTime;  // ����� �����
	int hunger;    // �����
	int cycle_r;   // ���� �����������
	static unsigned int count;

public:

	Predator(Cell * = nullptr, Values * = nullptr);
	~Predator();
	int getType();
	void setObject(int, int);
	int getObject(int);
	void live();
	static unsigned int getCount();
};

#endif