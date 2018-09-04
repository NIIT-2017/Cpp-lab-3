#include "Stone.h"
#include <iostream>
//#include <qDebug>

using namespace std;

size_t Stone::Stonecount = 0;

size_t Stone::getCount()
{
    //return Stonecount2();
   return Stonecount;
   // Stone *stone = new Stone;
    //size_t  i = stone->Stonecount2()-1;
    //delete stone;
    //return i;
    //return Stonecount2();
}

char Stone::getName()
{
	return STONE_N;
}

//http://faqs.org.ru/progr/c_cpp/cpp_lite3.htm


size_t &Stone::Stonecount2()
{
   //size_t num =0;
    static size_t* Stonecount2 = new size_t;
    return *Stonecount2;
    //Stonecount++;
}

Stone::Stone(Cell * c) :Object(c)
{	
    Stonecount2()++;
    Stonecount++;
    //Stonecount=Stonecount2();
}
Stone::~Stone()
{
    Stonecount--;
    this->Stonecount2()--;
    //Stonecount--;
}
void Stone::live()
{
}
