#pragma once

#include <iostream>
#include "../../datatypes/Fecha/DtFecha.h"
#include "../../datatypes/Hora/DtHora.h"
#include "../../datatypes/Consumido/DtConsumido.h"
#include "../../datatypes/Factura/DtFactura.h"
#include "../../ICollection/interfaces/IDictionary.h"

using namespace std;

class Factura
{
private:
    int codigo;
    int codigoVenta;
    int descuento;
    float subtotal;
    float montoTotal;
    float ivaTotal;
    IDictionary *productosConsumidos;
    DtFecha fecha;
    DtHora hora;

public:
    Factura(DtFactura);
    int getCodigo();
    int getDescuento();
    float getSubtotal();
    float getMontoTotal();
    float getIvaTotal();
    DtFecha getFecha();
    DtHora getHora();
    DtFactura getDatos();
    virtual ~Factura();
};