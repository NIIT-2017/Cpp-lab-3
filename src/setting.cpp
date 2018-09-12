#include "setting.h"
#include <cstring>
#include <string>
//#include <iostream>
#include <fstream>
#include <sstream>
//using namespace std;
Setting::Setting()
{

}

size_t Setting::getParamFromFille(std::string &text)
{
    std::string line;
    std::string needtext;
    size_t  result;
    std::ifstream file ("Setting.txt");
    bool flag = true;
    if (file.is_open())
    {
        while (!(file.eof()) && (flag == true)  )
        {
            std::getline (file,line);
            int fnd=line.find(text);
            while ((fnd>0) && (flag == true))
            {
                int first= line.find('=');
                int last= line.find(';');

                needtext = line.substr(first+2,last - first - 2);
                flag = false;
            }
        }
        std::stringstream sstream(needtext);
        sstream >> result;
    }
    file.close();
    return result;
}
