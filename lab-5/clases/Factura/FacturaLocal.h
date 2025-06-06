#pragma once

#include <iostream>
#include "Factura.h"
#include "../../datatypes/Factura/DtFacturaLocal.h"

using namespace std;

class FacturaLocal : public Factura
{
private:
    string nombreMozo;

public:
    FacturaLocal(DtFacturaLocal);
    string getNombreMozo();
    DtFacturaLocal getDatos();
    ~FacturaLocal();
};