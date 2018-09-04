#ifndef _COMMON_H_
#define _COMMON_H_
#include <cstring>
#include <string>
using namespace std;
typedef size_t coord_t;

struct Pair
{
	coord_t x; // 0..M-1
	coord_t y; // 0..N-1
};

class Setting
{
public:
	Setting();
	size_t getFromFile(string &txt);
};





#endif