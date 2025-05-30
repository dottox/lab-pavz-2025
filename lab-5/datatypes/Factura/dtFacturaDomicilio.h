#pragma once

#include <iostream>
#include "dtFactura.h"
#include "../../enums/Transporte.h"

using namespace std;

class dtFacturaDomicilio : public dtFactura{
private:
    string nombreRepartidor;
    Transporte transporte;

public:
    dtFacturaDomicilio();
    dtFacturaDomicilio(int, dtFecha, dtHora, dtConsumido **, float, int, float, float, Venta*, string, Transporte);
    string getNombreRepartidor();
    Transporte getTransporte();
    ~dtFacturaDomicilio();
};