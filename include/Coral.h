#ifndef _CORAL_H_
#define _CORAL_H_

#include "Object.h"
#include "Cell.h"
#include "Stone.h"


enum class relationship {PARENT, CHILDREN};
class Coral : public Stone
{
public:
	Coral(Cell * = nullptr);
	~Coral();
	void live();
	void breed();
	static unsigned int getCount();
	ObjType getType();
	char getName();
protected:
	static unsigned int count;
	void setRelationship(relationship);
	size_t liveBreeding = 5;
	size_t num = 0; // будет увеличиваться, пока время размножения не закончится. нужно, для того, чтобы организовать цикл с ростом коралла
	relationship rel = relationship::PARENT;
	
};



#endif
