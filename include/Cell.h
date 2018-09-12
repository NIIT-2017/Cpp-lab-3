#pragma once
#include "Object.h"
#include "Common.h"

//  Для работы с океаном для того чтобы создать укзатель
class Ocean;

class Cell
{
private: 
	Pair crd;
	Object *obj;
	Ocean *ocean;
public:
	explicit Cell(Pair p = {0, 0}, Ocean * oc = nullptr) : crd(p), obj(nullptr), ocean(oc)
	{}

	void init(Pair p, Ocean* oc);
	Object * getObject() const;
	Ocean * getOcean() const;
	void setObject(Object* c);
	void killMe();
	coord_t getX();
	coord_t getY();
};