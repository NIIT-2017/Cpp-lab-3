#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "Object.h"

class Ocean;

class Cell
{
	friend Ocean;
private:
	Pair crd;
	Object *obj=nullptr;
	
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		crd(p),
		obj(nullptr),
		ocean(oc) {}
	void init(Pair p, Ocean* oc);
	Ocean *ocean;
	Object* getObject() const;
    void setObject( Object*);
	void killMe();
	//bool CanMove(int direction);
    bool IsExists(const int x, const int y);
	size_t get_x();
	size_t get_y();
    Cell* offset(const int x,const int y);
	Ocean* getOcean();
    bool CellIsFree( Cell*  cell);
    bool CellHasObject(const char NameObj);
    void MoveObj(Cell  * cell1, Cell  * cell2);

};



#endif
