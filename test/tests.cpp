#include "Ocean.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <gtest/gtest.h>
#include <set>
#include <algorithm>
#include "Coral.h"


TEST(lab3, ocean1)
{
    Ocean *atlantic = new Ocean;
    atlantic->addObjects(3,4,10,5);
    EXPECT_EQ(Coral::getCount(), 4);
    EXPECT_EQ(Prey::getCount(), 10);
    int end = atlantic->RunForeTest();
    EXPECT_EQ(end, 100);
    delete atlantic;
}

TEST(lab3, ocean2)
{
    Ocean *atlantic = new Ocean;
    atlantic->addObjects(5,6,7,8);
    EXPECT_EQ(Coral::getCount(), 6);
    EXPECT_EQ(Predator::getCount(), 8);
    int end = atlantic->RunForeTest();
    EXPECT_EQ(end, 100);
    delete atlantic;
}

TEST(lab3, ocean3)
{
    Ocean *atlantic = new Ocean;
    atlantic->addObjects(1,2,3,4);
    EXPECT_EQ(Stone::getCount(), 1);
    EXPECT_EQ(Coral::getCount(), 2);
    EXPECT_EQ(Prey::getCount(), 3);
    int end = atlantic->RunForeTest();
    EXPECT_EQ(end, 100);
    delete atlantic;
}
