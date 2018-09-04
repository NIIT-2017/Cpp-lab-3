#include "Cell.h"
#include "Ocean.h"
#include "common.h"
using namespace std;

void Cell::init(Pair p, Ocean* oc)
{
	crd = p;
	ocean = oc;
}
Object* Cell::getObject() const
{
	return obj;
}
void Cell::setObject(Object *obj)
{
	this->obj = obj;
}

void Cell::killMe()
{
	if (obj)
	{
		delete obj;
		this->obj = nullptr;
	}
}
bool Cell::IsExists(const int x, const int y)
{
	Setting setting;
	string Rows = "Rows";
	string Columns = "Columns";
	int Row = setting.getFromFile(Rows);
	int Column = setting.getFromFile(Columns);
	if (((x < Column) && (y < Row)) && (x >= 0 && y >= 0))
		return true;
	else return false;
}
size_t Cell::get_x()
{
	return crd.x;
}

size_t Cell::get_y()
{
	return crd.y;
}

Cell* Cell::offset(const int x, const int y)
{
	Cell *cell = ocean->getCells(crd.x + x, crd.y + y);
	return cell;
}

Ocean * Cell::getOcean()
{
	return ocean;
}

bool Cell::IsFree(Cell * cell)
{
	if (getObject() == nullptr)
		return true;
	else return false;
}

bool Cell::HasObj(const char NameObj)
{
	if (IsFree(this)) return false;
	else if (obj->getName() == NameObj)
		return true;
	else return false;
}
void Cell::move(Cell  * c1, Cell  * c2)
{
	
	c2->obj = c1->obj;
	c1->obj = nullptr;
}