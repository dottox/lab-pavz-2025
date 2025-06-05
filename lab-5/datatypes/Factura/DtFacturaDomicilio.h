#pragma once

#include <iostream>
#include "DtFactura.h"
#include "../../enums/Transporte.h"

using namespace std;

class DtFacturaDomicilio : public DtFactura
{
private:
    string nombreRepartidor;
    Transporte transporte;

public:
    DtFacturaDomicilio();
    DtFacturaDomicilio(int, DtFecha, DtHora, IDictionary *, float, int, float, float, string, Transporte);
    string getNombreRepartidor();
    Transporte getTransporte();
    ~DtFacturaDomicilio();
};