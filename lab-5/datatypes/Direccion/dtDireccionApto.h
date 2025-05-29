#pragma once

#include <iostream>
#include "dtDireccion.h"

using namespace std;

class dtDireccionApto : public dtDireccion
{
private:
    string nombre;
    int numeroApto;

public:
    dtDireccionApto(string, int, string, string, int);
    string getNombre();
    int getNumeroApto();
    virtual ~dtDireccionApto();
};