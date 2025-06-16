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
    friend ostream& operator<<(ostream&, const DtDireccionApto&);
    virtual ~DtDireccionApto();
};