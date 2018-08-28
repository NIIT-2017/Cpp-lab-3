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
	unsigned int liveBreeding = 5;
	unsigned int num = 0; // ����� �������������, ���� ����� ����������� �� ����������. �����, ��� ����, ����� ������������ ���� � ������ �������
	relationship rel = relationship::PARENT;
	
};



#endif
