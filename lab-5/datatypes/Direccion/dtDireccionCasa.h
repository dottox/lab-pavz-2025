#pragma once

#include <iostream>
#include "dtDireccion.h"

using namespace std;

class dtDireccionCasa : public dtDireccion
{
private:
public:
    dtDireccionCasa(string, int, string);
    virtual ~dtDireccionCasa();
};