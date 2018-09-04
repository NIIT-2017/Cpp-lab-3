#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "Cell.h"
#include <list>
#include <vector>
using namespace std;
#include <cstdlib>

class Ocean
{
	
private:

	Cell * *cells;
	vector<Object*> stuff;

public:
	Ocean();
	~Ocean();
	void print() const;
	void addObjects(size_t, size_t, size_t, size_t);
	void run();
        int RunForTest();
	Cell* getCells(int x, int y);
	void DeleteObject(Object*);
	void addObject(Object*);
	void add(size_t, int);
	bool isLive();
	unsigned int isEnd();
	
   bool NoMoreLiveObject();
};

#endif 