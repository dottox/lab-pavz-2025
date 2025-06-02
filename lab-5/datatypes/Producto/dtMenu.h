#pragma once

#include <iostream>
#include "dtProducto.h"

using namespace std;

class dtMenu : public dtProducto
{
public:
    dtMenu();
    dtMenu(string, string, float);
    ~dtMenu();
};
