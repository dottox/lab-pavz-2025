#pragma once

#include <iostream>
#include "../Fecha/dtFecha.h"
#include "../Hora/dtHora.h"
#include "../Consumido/dtConsumido.h"
#include "../../clases/Venta/Venta.h"


using namespace std;

class dtFactura
{
private:
    int codigo;
    int codigoVenta;
    dtFecha fecha;
    dtHora hora;
    dtConsumido **productos;
    float subtotal;
    int descuento;
    float montoTotal;
    float ivaTotal;
    Venta* venta;

public:
    dtFactura();
    dtFactura(int, dtFecha, dtHora, dtConsumido **, float, int, float, float, Venta*);
    dtFactura getFactura();
    int getCodigo();
    int getCodigoVenta();
    dtFecha getFecha();
    dtHora getHora();
    dtConsumido **getProductos();
    float getSubtotal();
    int getDescuento();
    float getMontoTotal();
    float getIvaTotal();
    Venta* getVenta();
    ~dtFactura();
};