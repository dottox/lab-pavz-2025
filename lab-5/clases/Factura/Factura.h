#pragma once

#include <iostream>
#include "../../datatypes/Fecha/DtFecha.h"
#include "../../datatypes/Hora/DtHora.h"
#include "../../datatypes/Consumido/DtConsumido.h"
#include "../../datatypes/Factura/DtFactura.h"

using namespace std;

class Factura{
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
        Factura(DtFactura);
        int getCodigo();
        DtFecha getFecha();
        DtHora getHora();
        DtConsumido **getProductos();
        float getSubtotal();
        int getDescuento();
        float getMontoTotal();
        float getIvaTotal();
        virtual ~Factura();
};