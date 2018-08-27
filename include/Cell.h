#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "Object.h"

struct Values
{
	int Stone;

	int Coral;
	int liveTime1;  // Длина жизни корала
	int cycle_r1;   // Цикл размножения корала

	int Prey;
	int liveTime2;  // Длина жизни рыбы-жертвы
	int hunger2;    // Голод рыбы-жертвы
	int cycle_r2;   // Цикл размножения рыбы-жертвы

	int Predator;
	int liveTime3;  // Длина жизни хищника
	int hunger3;    // Голод хищника
	int cycle_r3;   // Цикл размножения хищника
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


