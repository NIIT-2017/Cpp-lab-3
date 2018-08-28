#include "Ocean.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Ocean.h"
#include <set>
#include <algorithm>



using namespace std;
int main()
{
	srand(time(nullptr));
	Ocean *atlantic = new Ocean("Ocean_Parametrs.txt");
	atlantic->addObjects(1000);
	atlantic->run();
	delete atlantic;
	return 0;
}
