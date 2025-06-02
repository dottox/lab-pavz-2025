#pragma once

#include <iostream>
#include "DtDireccion.h"

using namespace std;

class DtDireccionCasa : public DtDireccion
{
private:
public:
    DtDireccionCasa(string, int, string);
    virtual ~DtDireccionCasa();
};