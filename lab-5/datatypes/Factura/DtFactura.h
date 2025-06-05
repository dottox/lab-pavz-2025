#pragma once

#include <iostream>
#include "../Fecha/DtFecha.h"
#include "../Hora/DtHora.h"
#include "../Consumido/DtConsumido.h"
#include "../../ICollection/interfaces/IDictionary.h"

using namespace std;

class DtFactura
{
private:
    int codigo;
    int codigoVenta;
    DtFecha fecha;
    DtHora hora;
    IDictionary *productosConsumidos;
    float subtotal;
    int descuento;
    float montoTotal;
    float ivaTotal;

public:
    DtFactura();
    DtFactura(int, DtFecha, DtHora, IDictionary *, float, int, float, float);
    DtFactura(int, int, DtFecha, DtHora, IDictionary *, float, int, float, float);
    DtFactura getFactura();
    int getCodigo();
    int getCodigoVenta();
    DtFecha getFecha();
    DtHora getHora();
    IDictionary *getProductos();
    float getSubtotal();
    int getDescuento();
    float getMontoTotal();
    float getIvaTotal();
    virtual ~DtFactura();
};