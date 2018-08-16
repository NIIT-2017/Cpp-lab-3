#include "Ocean.h"

int main()
{
	Ocean *atlantic = new Ocean("config.json");
	atlantic->run();

	delete atlantic;

	return 0;
}