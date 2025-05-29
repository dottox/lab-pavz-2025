#pragma once

#include <iostream>
#include "dtFactura.h"

using namespace std;

class dtFacturaLocal : public dtFactura
{
private:
    string nombreMozo;

public:
    dtFacturaLocal();
    dtFacturaLocal(int, dtFecha, dtHora, dtConsumido **, float, int, float, float, Venta*, string);
    string getNombreMozo();
    ~dtFacturaLocal();
};