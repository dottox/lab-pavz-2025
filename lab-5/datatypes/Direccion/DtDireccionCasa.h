#pragma once

#include <iostream>
#include "DtDireccion.h"

using namespace std;

class DtDireccionCasa : public DtDireccion
{
private:
public:
    DtDireccionCasa(string, string, string);
    friend ostream& operator<<(ostream&, const DtDireccionCasa&);
    virtual ~DtDireccionCasa();
};