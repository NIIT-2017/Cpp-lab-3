#include "gtest/gtest.h"


#include "Cell.h"
#include "Common.h"
#include "Coral.h"
#include "Object.h"
#include "Ocean.h"
#include "Predator.h"
#include "Prey.h"
#include "Stone.h"

TEST(lab3, ocean1)
{
	Ocean *oc = new Ocean("Config_file_config_is_bed.txt");
	oc.addObject(STONE_SIZE, CORAL_SIZE, PREY_SIZE, PREDATOR_SIZE);
	oc.print();
	int result = oc->run();
	EXPECT_EQ(result, BED_CONFIG_FILE);
	delete oc;
}

TEST(lab3, ocean2)
{
	Ocean *oc = new Ocean("Config_file_no_live.txt");
	oc.addObject(STONE_SIZE, CORAL_SIZE, PREY_SIZE, PREDATOR_SIZE);
	oc.print();
	int result = oc->run();
	EXPECT_EQ(result, ALL_LIVING_DIE);
	delete oc;
}

TEST(lab3, ocean3)
{
	Ocean *oc = new Ocean("Config_file_predator_win.txt");
	oc.addObject(STONE_SIZE, CORAL_SIZE, PREY_SIZE, PREDATOR_SIZE);
	oc.print();
	int result = oc->run();
	EXPECT_EQ(result, PREDATOR_WIN);
	delete oc;
}


TEST(lab3, ocean4)
{
	Ocean *oc = new Ocean("Config_file_prey_win.txt");
	oc.addObject(STONE_SIZE, CORAL_SIZE, PREY_SIZE, PREDATOR_SIZE);
	oc.print();
	int result = oc->run();
	EXPECT_EQ(result, PREY_WIN);
	delete oc;
}
