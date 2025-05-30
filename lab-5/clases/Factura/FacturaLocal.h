#pragma once

#include <iostream>
#include "Factura.h"
#include "../../datatypes/Factura/dtFacturaLocal.h"

using namespace std;

class FacturaLocal : public Factura{
private:
    string nombreMozo;

public:
    FacturaLocal(dtFacturaLocal);
    string getNombreMozo();
    ~FacturaLocal();
};