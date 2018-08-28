#ifndef _OBJECT_H_
#define _OBJECT_H_
#include "common.h"


#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType : unsigned int {STONE,CORAL,PREY,PREDATOR};

class Cell;
class Object
{
protected:
	Cell *cell;
	static unsigned int count;
public:
	Object(Cell * = nullptr);	
	virtual ~Object();
	virtual void live() = 0; // жизнь объекта
	void setCell(Cell*);
	virtual char getName() = 0;
	virtual ObjType getType() = 0;
	Cell * getCell() const;
	static unsigned int getCount();	
};

#endif