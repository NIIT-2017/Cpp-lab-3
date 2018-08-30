#ifndef SETTING_H
#define SETTING_H
#include <cstring>
#include <string>
#include "common.h"

class Setting
{
public:
    Setting();
    size_t getParamFromFille(std::string & text);
};

#endif // SETTING_H
