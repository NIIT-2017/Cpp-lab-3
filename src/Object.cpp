#include "Object.h"
#include <cstdlib>
//#include <cstring>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

size_t Object::count = 0;
size_t Object::getCount()
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
