#pragma once

#include <iostream>
#include "../Fecha/DtFecha.h"
#include "../Hora/DtHora.h"
#include "../Consumido/DtConsumido.h"


using namespace std;

class DtFactura{
private:
    int codigo;
    int codigoVenta;
    DtFecha fecha;
    DtHora hora;
    DtConsumido **productos;
    float subtotal;
    int descuento;
    float montoTotal;
    float ivaTotal;

public:
    DtFactura();
    DtFactura(int, DtFecha, DtHora, DtConsumido **, float, int, float, float);
    DtFactura(int, int, DtFecha, DtHora, DtConsumido **, float, int, float, float);
    DtFactura getFactura();
    int getCodigo();
    int getCodigoVenta();
    DtFecha getFecha();
    DtHora getHora();
    DtConsumido **getProductos();
    float getSubtotal();
    int getDescuento();
    float getMontoTotal();
    float getIvaTotal();
    virtual ~DtFactura();
};