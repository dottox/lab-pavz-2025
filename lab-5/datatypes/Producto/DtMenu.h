#pragma once

#include <iostream>
#include "DtProducto.h"


using namespace std;

class DtMenu : public DtProducto
{
public:
    DtMenu();
    DtMenu(char*, string);
    ~DtMenu();
};
