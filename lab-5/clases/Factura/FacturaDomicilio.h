#pragma once

#include <iostream>
#include "Factura.h"
#include "../../enums/Transporte.h"
#include "../../datatypes/Factura/dtFacturaDomicilio.h"

using namespace std;

class FacturaDomicilio : public Factura
{
private:
    string nombreRepartidor;
    Transporte transporte;

public:
    FacturaDomicilio(dtFacturaDomicilio);
    string getNombreRepartidor();
    Transporte getTransporte();
    ~FacturaDomicilio();
};