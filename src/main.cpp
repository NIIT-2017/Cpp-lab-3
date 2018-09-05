#include "Common.h"
#include "Ocean.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

extern size_t STONE_SIZE;
extern size_t CORAL_SIZE;
extern size_t PREY_SIZE;
extern size_t PREDATOR_SIZE;

int main()
{
	srand((unsigned int)time(NULL));
	Ocean oc((char *)"Config_file_prey_win.txt");
	if (oc.getConfigFileOpen() == false)
	{
		cout << endl << "Not open config file." << endl;
			return 0;
	}
	oc.addObject(STONE_SIZE, CORAL_SIZE, PREY_SIZE, PREDATOR_SIZE);
	oc.print();
	int result = oc.run();
	if (result == ALL_LIVING_DIE)
		cout << "ALL A LIFE IS DIE" << endl;
	else if (result == PREY_WIN)
		cout << "PREY WIN" << endl;
	else if (result == PREDATOR_WIN)
		cout << "PREDATOR WIN" << endl;
	else if (result == BED_CONFIG_FILE)
		cout << "BED CONFIG FILE" << endl;
	return 0;
}