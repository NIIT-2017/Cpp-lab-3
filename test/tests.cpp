#include "ocean.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <gtest/gtest.h>
#include <set>
#include <algorithm>
#include "Coral.h"


TEST(lab3, ocean1)
{
	Ocean *atlantic = new Ocean("Ocean_Parametrs.txt");
	EXPECT_EQ(atlantic->getSize(), 0);
	atlantic->addObjects(100);
	EXPECT_EQ(atlantic->getSize(), 100);
	atlantic->run();
	delete atlantic;
}

TEST(lab3, ocean2)
{
	Ocean *atlantic = new Ocean("Ocean_Parametrs.txt");
	EXPECT_EQ(atlantic->getSize(), 0);
	atlantic->addObjects(96, ObjType::CORAL);
	EXPECT_EQ(Coral::getCount(), 96);
	size_t end = atlantic->run();
	EXPECT_EQ(end, 3);
	delete atlantic;
	EXPECT_EQ(Coral::getCount(), 0);
}

TEST(lab3, ocean3)
{
	Ocean *atlantic = new Ocean("Ocean_Parametrs2.txt");
	EXPECT_EQ(atlantic->getSize(), 0);
	atlantic->addObjects(2, ObjType::CORAL);
	atlantic->addObjects(2, ObjType::STONE);
	EXPECT_EQ(Coral::getCount(), 2);
	EXPECT_EQ(Stone::getCount(), 2);
	size_t end = atlantic->run();
	EXPECT_EQ(end, 2);
	delete atlantic;
}