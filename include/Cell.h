#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "Object.h"

struct Values
{
	int Stone;

	int Coral;
	int liveTime1;  // ����� ����� ������
	int cycle_r1;   // ���� ����������� ������

	int Prey;
	int liveTime2;  // ����� ����� ����-������
	int hunger2;    // ����� ����-������
	int cycle_r2;   // ���� ����������� ����-������

	int Predator;
	int liveTime3;  // ����� ����� �������
	int hunger3;    // ����� �������
	int cycle_r3;   // ���� ����������� �������
};

class Ocean;

class Cell
{
	friend Ocean;
private:
	Pair crd;
	Object *obj;
	Ocean *ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		crd(p),
		obj(nullptr),
		ocean(oc) {}
	void init(Pair p, Ocean* oc);
	Object* getObject() const;
	void setObject(Object*);
	void killMe();

};



#endif