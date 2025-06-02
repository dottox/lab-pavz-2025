#pragma once

#include <iostream>
#include "DtFactura.h"

using namespace std;

class DtFacturaLocal : public DtFactura
{
private:
    string nombreMozo;

public:
    DtFacturaLocal();
    DtFacturaLocal(int, DtFecha, DtHora, DtConsumido **, float, int, float, float, string);
    string getNombreMozo();
    ~DtFacturaLocal();
};