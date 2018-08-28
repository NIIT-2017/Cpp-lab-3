#pragma once
#ifndef _COMMON_H_
#define _COMMON_H_

typedef unsigned int size_t;
typedef size_t coord_t;

struct Pair
{
	coord_t x; // 0..M-1
	coord_t y; // 0..N-1
};

inline bool operator<(const Pair & p1, const Pair & p2)
{
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

inline bool Clamp(int value, int min, int max)
{
	return (value >= min) && (value <= max);
}
struct Values
{
	size_t N = 40;
	size_t M = 100;

	size_t LIVE_TIME_STONE = 10;

	size_t LIVE_TIME_CORAL = 15;
	size_t BREED_TIME_CORAL = 3;

	size_t LIVE_TIME_PREY = 5;
	size_t BREED_TIME_PREY = 3;

	size_t LIVE_TIME_PREDATOR = 9;
	size_t BREED_TIME_PREDATOR = 3;
	size_t FOOD_TIME_PREDATOR = 5;
};




#endif
