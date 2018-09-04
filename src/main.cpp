#include "common.h"
#include "Ocean.h"
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Coral.h"
#include "Object.h"
using namespace std;
int main()
{
	Ocean *atlantic = new Ocean;
    atlantic->addObjects(3,4,2,1);
    size_t a = Coral::getCount();
    
    int i = atlantic->RunForTest();
    
    delete atlantic;
}