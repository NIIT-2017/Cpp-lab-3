#include "common.h"
#include "ocean.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(nullptr));
	
	Ocean *atlantic = new Ocean;
	atlantic->run();

	return 0;
}