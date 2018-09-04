#include "common.h"
#include "ocean.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Object.h"
#include "setting.h"

#include "Coral.h"
using namespace std;

int main()
{
    //++
//    Ocean *atlantic = new Ocean;
//    Setting seting;
//    string StoneNum = "StoneNum";
//    string CoralNum = "CoralNum";
//    string PreylNum = "PreylNum";
//    string PredatorlNum = "PredatorlNum";
//    atlantic->addObjects(seting.getParamFromFille(StoneNum),seting.getParamFromFille(CoralNum),
//                         seting.getParamFromFille(PreylNum),seting.getParamFromFille(PredatorlNum));
//    atlantic->run();
//    delete atlantic;
    //int i =atlantic->RunForeTest();
    //--

//++
    Ocean *atlantic = new Ocean;
    atlantic->addObjects(3,4,2,1);
    size_t hhgj = Coral::getCount();
    //EXPECT_EQ(Coral::getCount(), 4);
    //EXPECT_EQ(Prey::getCount(), 10);
    int i = atlantic->RunForeTest();
    //EXPECT_EQ(end, 100);
    delete atlantic;
    //--
    return 0;
}
