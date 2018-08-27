#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "Cell.h"
#include <list>

class Ocean
{
private:
	size_t N = 20;
	size_t M = 50;
	Cell **cells;
	int tt;
	Values val;

public:
	~Ocean();
	void print() const;
	void addObjects(int, int);
	void run();
	void oceanLive();
	void createObject(size_t, size_t, int);
	void objectLive(size_t, size_t, int);
	void copy(int, int, int, int);
	bool read(char*);
	int fill(char*, int, int);
};


#endif