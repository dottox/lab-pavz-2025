#pragma once

#include <iostream>

#include "../../ICollection/interfaces/IDictionary.h"

class DtInforme
{
private:
    float totalIngresos;
    IDictionary *ventas;

public:
    DtInforme(float totalIngresos, IDictionary *ventas);
    float getTotalIngresos();
    IDictionary *getVentas();
    virtual ~DtInforme();
};
