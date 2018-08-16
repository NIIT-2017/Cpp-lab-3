#ifndef _COMMON_H_
#define _COMMON_H_

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

typedef unsigned long size_t;
typedef size_t coord_t;

struct Pair
{
	coord_t x;
	coord_t y;
};

extern rapidjson::Document g_data;

/*enum class ObjType : char
{ STONE = '#', CORAL = '*', PREY = 'f', PREDATOR = 'S' };*/

enum class ObjType : char
{ STONE, CORAL, PREY, PREDATOR };


#endif