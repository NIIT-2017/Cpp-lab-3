#include "Cell.h"
#include "Ocean.h"
#include <iostream>
#include "setting.h"
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
    if (getObject())
	{ 
        Object* obj = getObject();
        ocean->DeleteObject(obj);
        delete getObject();
        this->obj = nullptr;
	}
}
bool Cell::IsExists(const int x,const  int y)
{
    Setting seting;
    std::string NumRows = "NumRows";
    std::string NumColumns = "NumColumns";
    size_t Row = seting.getParamFromFille(NumRows);
    size_t Columns = seting.getParamFromFille(NumColumns);
    if ( ((x < Columns) &&  (y < Row) ) && (x >= 0 &&  y >= 0 ))
		return true;
	else return false;
}

size_t Cell::get_x()
{
	return this->crd.x;	
}

size_t Cell::get_y()
{
	return this->crd.y;
}

Cell *Cell::offset(const int x, const int y)
{
	Cell *cell = this->getOcean()->getcells((this->crd.x + x), (this->crd.y + y));
	return cell;
}

Ocean * Cell::getOcean()
{
	return ocean;
}

bool Cell::CellIsFree( Cell  * cell)
{
    if (cell->getObject() == nullptr) {
        return true;
	}
    else return false;
}


bool Cell::CellHasObject(const char NameObj)
{
   if (this->CellIsFree(this)) return false;
    else if (this->getObject()->getName() == NameObj)
    return true;
    else return false;
}

void Cell::MoveObj(Cell  * cell1, Cell  * cell2)
{
    cell2->obj=cell1->obj;
    cell1->obj=nullptr;
}
