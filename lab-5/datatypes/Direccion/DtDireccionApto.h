#pragma once

#include <iostream>
#include "DtDireccion.h"

using namespace std;

class DtDireccionApto : public DtDireccion
{
private:
    string nombre;
    string numeroApto;

public:
    DtDireccionApto(string, string, string, string, string);
    string getNombre();
    string getNumeroApto();
    virtual ~DtDireccionApto();
};