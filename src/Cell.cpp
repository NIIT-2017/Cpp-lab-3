#include "Cell.h"
#include "Ocean.h"

Cell::Cell(Pair p, Ocean *oc) :
	crd(p),
	obj(nullptr),
	ocean(oc)
{}

//инициализация ячейки
void Cell::init(Pair p, Ocean *oc)
{
	crd = p;
	ocean = oc;
}

//рождение объекта в ячейке, если в ячейке нет объекта
void Cell::bornObject(ObjType objType)
{
	if (!obj)
		ocean->addObjects(crd, objType);
}

//запросить ячейку у океана и вернуть объекту
//нужно для движения и размножения в случайную сторону
Cell* Cell::getCell()
{
	return ocean->getCell(crd);
}

Object* Cell::getObject() const
{
	return obj;
}

void Cell::setObject(Object *obj)
{
	this->obj = obj;
}

//уничтожить в ячейке объект, с освобождением ячейки
//но уничтожаемый объект может уже не быть в ячейке,
//а в ячейке может быть уже новый объект, поэтому новый не трогаем, а старый уничтожаем
void Cell::killMe(Object *objs)
{
	ocean->delObject(objs);
	if (obj == objs)
	{
		delete obj;
		obj = nullptr;
	}
	else delete objs;
}

//записать объект в список умерших в океане
void Cell::setKill()
{
	if (obj)
	{
		ocean->setDelObject(obj);
		obj->setLive(false);
	}
}

//записать объект в список рождающихся в океане
void Cell::setBorn(ObjType objType)
{
	ocean->setBornObject(this, objType);
}