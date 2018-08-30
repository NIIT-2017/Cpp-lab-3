#ifndef _COMMON_H_
#define _COMMON_H_
#include <cstring>

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum  ObjType {STONE = 1,CORAL = 2,PREY = 3,PREDATOR = 4};

typedef size_t coord_t;

struct Pair
{
	coord_t x; // 0..M-1
	coord_t y; // 0..N-1
};

//const size_t N = 3;//Rows
//const size_t M = 3;//Columns

//const size_t StoneNum = 2;//

//const size_t CoralNum = 2;//
//const size_t Coral_Breeding_Cycle = 3;//


//const size_t PreylNum = 4;//
//const size_t Prey_Breeding_Cycle = 4;
//const size_t Prey_live_Time = 100;

//const size_t PredatorlNum = 3;//
//const size_t Predator_Breeding_Cycle = 3;
//const size_t Predator_live_Time = 100;
//const size_t Predator_Hungry_Time = 20;

#endif

