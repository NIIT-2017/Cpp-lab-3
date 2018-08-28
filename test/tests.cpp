#include "gtest/gtest.h"
#include "common.h"
#include "Ocean.h"
#include "Stone.h"
#include "Coral.h"
#include "Prey.h"
#include "Predator.h"
#include "Cell.h"
#include "Object.h"
#include <iostream>


TEST(lab3,ocean_1)
{
    Ocean *atlantic =new Ocean;
		
    bool result=atlantic->read("Test1.txt");

    EXPECT_EQ(1,result);
}


TEST(lab3,ocean_2)
{
    Ocean *atlantic =new Ocean;	
	
    bool result=atlantic->read("Test2.txt");

    EXPECT_EQ(1,result);
}


TEST(lab3,ocean_3)
{
    Ocean *atlantic =new Ocean;
	
    char ch[200] = "Coral";
	
	
    int result=atlantic->fill(ch, 1, 4);

    EXPECT_EQ(4,result);
}


TEST(lab3,ocean_4)
{
    Ocean *atlantic =new Ocean;
	
    char ch[200] = "Predator";
	
	
    int result=atlantic->fill(ch, 1, 11);


     
    EXPECT_EQ(11,result);
}


TEST(lab3,ocean_5)
{
    Ocean *atlantic =new Ocean;
	
    char ch[200] = "feedCycle";
	
	
    int result=atlantic->fill(ch, 1, 9);

    EXPECT_EQ(9,result);
}

