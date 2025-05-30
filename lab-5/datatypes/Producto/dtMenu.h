#pragma once

#include <iostream>
#include "dtProducto.h"

using namespace std;

class dtMenu : public dtProducto
{
public:
    dtMenu();
    dtMenu(int, string, string, float);
    ~dtMenu();
};
