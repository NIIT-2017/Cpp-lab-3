#include "Predator.h"
#include "Ocean.h"
#include <iostream>
#include <string>
#include "setting.h"

using namespace std;
size_t Predator::count = 0;
//char         Object::name = CORAL_N;


size_t Predator::getCount()
{
    return count;
}

Predator::Predator(Cell * c) :Object(c)
{
    count++;
    Setting seting;
    std::string str;
    str = "Predator_Breeding_Cycle";
    this->breeding_cycle = seting.getParamFromFille(str);
    str = "Predator_live_Time";
    this->liveTime =  seting.getParamFromFille(str);
    str = "Predator_Hungry_Time";
    this->HungryTime = seting.getParamFromFille(str);
}

Predator::~Predator()
{
    count--;
}

void Predator::live()
{
    this->liveTime--;
    this->HungryTime--;
    if (this->liveTime == 0 || this->HungryTime == 0)//время умирать!
    {
        this->cell->killMe();
    }
    else {
        bool flag = true;
        int adress_x = this->cell->get_x();
        int adress_y = this->cell->get_y();
        if (this->breeding_cycle == 0)
        {//время размножения
            Setting seting;
            std::string str = "Predator_Breeding_Cycle";
            this->breeding_cycle = seting.getParamFromFille(str);
            int num=0;
            while(flag && (num < 9))
                //for (int i = adress_x - 1; i != adress_x + 2; i++)
            {
                int i1 = rand() % (3)-1;
                int i2 = rand() % (3)-1;
                while (((i1==0) && (i2==0)) && num < 9)
                {
                    i1 = rand() % (3)-1;
                    i2 = rand() % (3)-1;
                    num++;
                }
                num++;
                int i=adress_x + i1;
                int j=adress_y + i2;
                {
                    {
                        {
                            if (flag)
                            {
                                if (this->cell->IsExists(i,j))
                                {
                                    Cell* nextCell = this->cell->offset(i - adress_x, j - adress_y);
                                    if (this->cell->CellIsFree(nextCell) || (nextCell->CellHasObject(PREY_N)))
                                    {
                                        if (nextCell->CellHasObject(PREY_N))
                                        {
                                            nextCell->killMe();
                                            Setting seting;
                                            std::string str = "Predator_Hungry_Time";
                                            this->HungryTime = seting.getParamFromFille(str);
                                        }
                                        Object *born = new Predator(nextCell);
                                        nextCell->setObject(born);
                                        this->cell->getOcean()->addObject(born);
                                        //this->cell->MoveObj(this->cell,nextCell);
                                        flag=false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            flag=false;
        }
        else //move time
        {
            int num = 0;
            while(flag && (num < 9))
                //for (int i = adress_x - 1; i != adress_x + 2; i++)
            {
                int i1 = rand() % (3)-1;
                int i2 = rand() % (3)-1;
                //int num2 = 0;
                while (((i1==0) && (i2==0)) && num < 9)
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
                                    if (this->cell->CellIsFree(nextCell) || (nextCell->CellHasObject(PREY_N)))
                                    {
                                        if (nextCell->CellHasObject(PREY_N) )
                                        {
                                            nextCell->killMe();
                                            std::string str = "Predator_Hungry_Time";
                                            Setting seting;
                                            this->HungryTime =seting.getParamFromFille(str);
                                        }
                                        Predator *newPredator = new Predator(nextCell);
                                        newPredator->SetParamLive (this->liveTime, this->breeding_cycle, this->HungryTime );
                                        Object *born=newPredator;

                                        //Object *born = new Predator(nextCell);


                                        //born->SetParamLive (this->liveTime, this->breeding_cycle, this->HungryTime );
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
            flag=false;
        }
    }
}

char Predator::getName()
{
    return PREDATOR_N;
}

void Predator::SetParamLive(const int liveTime, const size_t breeding_cycle,const int HungryTime)
{
    this->liveTime = liveTime-1;
    this->breeding_cycle = breeding_cycle-1;
    this->HungryTime = HungryTime-1;

}

