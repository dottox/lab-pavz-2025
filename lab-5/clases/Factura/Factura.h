#pragma once

#include <iostream>
#include "../../datatypes/Fecha/DtFecha.h"
#include "../../datatypes/Hora/DtHora.h"
#include "../../datatypes/Consumido/DtConsumido.h"
#include "../../datatypes/Factura/DtFactura.h"
#include "../../datatypes/Factura/DtFacturaLocal.h"
#include "../../datatypes/Factura/DtFacturaDomicilio.h"
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
    int getCodigoVenta();
    int getDescuento();
    float getSubtotal();
    float getMontoTotal();
    float getIvaTotal();
    IDictionary *getProductos();
    DtFecha getFecha();
    DtHora getHora();
    virtual ~Factura();
};