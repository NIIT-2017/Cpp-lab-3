#include "Stone.h"
#include <iostream>
//#include <qDebug>

using namespace std;

size_t Stone::Stonecount = 0;

size_t Stone::getCount()
{
    //return Stonecount2();
    return Stonecount;

}

char Stone::getName()
{
	return STONE_N;
}

//http://faqs.org.ru/progr/c_cpp/cpp_lite3.htm


size_t &Stone::Stonecount2()
{
    size_t num =0;
    static size_t* Stonecount2 = new size_t;
    return *Stonecount2;
    //Stonecount++;
}

Stone::Stone(Cell * c) :Object(c)
{	
    Stonecount2()++;
    Stonecount++;
}
Stone::~Stone()
{
    this->Stonecount2()--;
    //Stonecount--;
}
void Stone::live()
{
}
