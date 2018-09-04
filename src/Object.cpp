#include "Object.h"
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;
unsigned int Object::count = 0;
unsigned int Object::getCount()
{
	return count;
}


Object::Object(Cell * c) :cell(c)
{
	
	count++;
}
Object::~Object()
{
	count--;
}

void Object::setCell(Cell* c)
{
	cell = c;
}

char Object::getName()
{
	return name;
}