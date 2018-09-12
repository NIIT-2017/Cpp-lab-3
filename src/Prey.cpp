#include "Prey.h"
#include "Ocean.h"
#include <iostream>
#include <string>
#include <cstring>
#include "setting.h"
using namespace std;

size_t Prey::count = 0;
//char         Object::name = CORAL_N;


size_t Prey::getCount()
{
    return count;
}

Prey::Prey(Cell * c) :Object(c)
{
    count++;
    Setting seting;
    std::string str= "Prey_Breeding_Cycle";
    this->breeding_cycle = seting.getParamFromFille(str);
    str = "Prey_live_Time";
    this->liveTime = seting.getParamFromFille(str);
}

Prey::~Prey()
{
    count--;
}

void Prey::live()
{
    this->liveTime--;
    if (this->liveTime == 0)
    {
        this->cell->killMe();
    }
    else
    {
        bool flag = true;
        int adress_x = this->cell->get_x();
        int adress_y = this->cell->get_y();
        if (breeding_cycle == 0)
        {
            Setting seting;
            std::string str="Prey_Breeding_Cycle";
            this->breeding_cycle = seting.getParamFromFille(str);
            int num = 0;
            while(flag && (num < 10))
            {
                int i1 = rand() % (3)-1;
                int i2 = rand() % (3)-1;
                while (((i1==0) && (i2==0)) && num < 10)
                {
                    i1 = rand() % (3)-1;
                    i2 = rand() % (3)-1;
                    num++;
                }
                num++;
                int i=adress_x + i1;
                int j= adress_y+ i2;
                {
                    {
                        {
                            if (flag)
                            {
                                if (this->cell->IsExists(i,j))
                                {
                                    Cell* nextCell = this->cell->offset(i - adress_x, j - adress_y);
                                    if (this->cell->CellIsFree(nextCell) || (nextCell->CellHasObject(CORAL_N)))
                                    {
                                        Object *born = new Prey(nextCell);

                                        nextCell->setObject(born);
                                        this->cell->getOcean()->addObject(born);
                                        flag = false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            flag = false;
        }
        else //move time
        {
            int num = 0;
            while(flag && (num < 9))
            {   int i1 = rand() % (3)-1;
                int i2 = rand() % (3)-1;
                while (((i1==0) && (i2==0)) && num!=9)
                {
                    i1 = rand() % (3)-1;
                    i2 = rand() % (3)-1;
                    num++;
                }
                num++;
                int i= adress_x + i1;
                int j= adress_y + i2;
                {
                    {
                        if (flag)
                        {
                            if (this->cell->IsExists(i,j))
                            {
                                Cell* nextCell = this->cell->offset(i - adress_x, j - adress_y);
                                if (this->cell->CellIsFree(nextCell) || (nextCell->CellHasObject(CORAL_N)) )
                                {
                                    if (nextCell->CellHasObject(CORAL_N) )
                                        nextCell->killMe();
                                    //this->cell->MoveObj(this->cell,nextCell);
                                    // std::cout << "Move from= " << adress_x<<" "<< adress_y<<std::endl;
                                    Prey *newPrey=new Prey(nextCell);
                                    newPrey->SetParamLive(this->liveTime, this->breeding_cycle);
                                    //Object *born = new Prey(nextCell);

                                    Object *born = newPrey;
                                    //born->SetParamLive(this->liveTime, this->breeding_cycle);
                                    nextCell->setObject(born);
                                    this->cell->getOcean()->addObject(born);
                                    this->cell->killMe();
                                    flag=false;
                                }
                            }
                        }
                    }
                }
            }
        }
        flag = false;
    }
}



char Prey::getName()
{
    return PREY_N;
}

//void Prey::addPrey()
//{

//}

void Prey::SetParamLive(int liveTime, size_t breeding_cycle)
{
    this->liveTime=liveTime-1;
    this->breeding_cycle= breeding_cycle-1;
}

