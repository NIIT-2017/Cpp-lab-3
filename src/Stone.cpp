#include "Stone.h"
#include <iostream>
using namespace std;

unsigned int Stone::count = 0;


unsigned int Stone::getCount()
{
	return count;
}

Stone::Stone(Cell * c) :Object(c)
{	
	count++;
}
Stone::~Stone()
{
	count--;
}
void Stone::live()
{}

char Stone::getName()
{
	return STONE_N;
}
