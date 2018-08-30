#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "Cell.h"
#include <list>
#include <vector>
//#include <map>//?правильнее так

class Ocean
{
private:
	Cell **cells;
	std::vector<Object*> stuff;
    //std::map <int, int> setting;//?
public:
	Ocean();
	~Ocean();
	void print() const;
	void addObjects(size_t, size_t, size_t, size_t);
	void run();
    int RunForeTest();
	Cell* getcells(int x, int y);
	void addObject(Object*);
    void DeleteObject(Object*);
    //template <typename T>
    //template <typename T>
    //Ocean::voidAdd(int count, int  type,class T)
    voidAdd(int count, int  type);
    unsigned int isEnd();
    bool NoMoreLiveOdject();
};


#endif
