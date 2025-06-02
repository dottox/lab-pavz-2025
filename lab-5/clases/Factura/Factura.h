#pragma once

#include <iostream>
#include "../../datatypes/Fecha/dtFecha.h"
#include "../../datatypes/Hora/dtHora.h"
#include "../../datatypes/Consumido/dtConsumido.h"
#include "../../datatypes/Factura/dtFactura.h"

using namespace std;

class Factura{
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
    public:
        Factura(dtFactura);
        int getCodigo();
        dtFecha getFecha();
        dtHora getHora();
        dtConsumido **getProductos();
        float getSubtotal();
        int getDescuento();
        float getMontoTotal();
        float getIvaTotal();
        virtual ~Factura();
};