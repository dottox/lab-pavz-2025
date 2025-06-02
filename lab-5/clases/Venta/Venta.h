#pragma once

#include <iostream>
#include "../Producto/Producto.h"
#include "../Factura/Factura.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/IDictionary.h"

using namespace std;

class Venta : ICollectible{
private:
    int codigo;
    int descuento;
    int cantidadProductos;
    float subtotal;
    Factura * factura;
    IDictionary * productos;

public:
    Venta(int, float, int, Producto **, int);
    int getCodigo();
    float getSubtotal();
    int getDescuento();
    //Producto **getProductos();
    int getCantidadProductos();
    bool estaFacturada();
    void setSubtotal(float);
    void setDescuento(int);
    void setProductos(Producto **, int);
    virtual ~Venta();
};