#pragma once

#include <iostream>
#include "../Producto/Producto.h"
#include "../Factura/Factura.h"

using namespace std;

class Venta
{
private:
    int codigo;
    float subtotal;
    int descuento;
    Producto **productos;
    int cantidadProductos;
    Factura *factura;

public:
    Venta(int, float, int, Producto **, int);
    int getCodigo();
    float getSubtotal();
    int getDescuento();
    Producto **getProductos();
    int getCantidadProductos();
    bool estaFacturada();
    void setSubtotal(float);
    void setDescuento(int);
    void setProductos(Producto **, int);
    virtual ~Venta();
};