#pragma once

#include <iostream>
#include "DtDireccion.h"

using namespace std;

class DtDireccionApto : public DtDireccion
{
private:
    string nombre;
    int numeroApto;

public:
    DtDireccionApto(string, int, string, string, int);
    string getNombre();
    int getNumeroApto();
    virtual ~DtDireccionApto();
};