#include "common.h"
#include "Ocean.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <locale.h>

using namespace std;
int main()
{
	setlocale(0, "");
	srand(time(nullptr));
	
	Ocean *atlantic = new Ocean;
	atlantic->run();

	return 0;
}
