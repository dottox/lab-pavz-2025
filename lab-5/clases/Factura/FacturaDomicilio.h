#pragma once

#include <iostream>
#include "Factura.h"
#include "../../enums/Transporte.h"
#include "../../datatypes/Factura/DtFacturaDomicilio.h"

using namespace std;

class FacturaDomicilio : public Factura
{
private:
    string nombreRepartidor;
    Transporte transporte;

public:
    FacturaDomicilio(DtFacturaDomicilio);
    string getNombreRepartidor();
    Transporte getTransporte();
    DtFacturaDomicilio getDatos();
    ~FacturaDomicilio();
};