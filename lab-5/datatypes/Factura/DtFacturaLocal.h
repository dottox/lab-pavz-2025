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
    DtFacturaLocal(DtFactura, string);
    string getNombreMozo();
    ~DtFacturaLocal();
};