#pragma once

#include <iostream>

#include "../Producto/Producto.h"
#include "../Venta/Venta.h"

using namespace std;

class ProductoVenta
{
private:
    Venta *venta;
    Producto *producto;
    int cantidad;

public:
    ProductoVenta(Venta *, Producto *, int);
    Venta *getVenta();
    Producto *getProducto();
    int getCantidad();
    void setCantidad(int);
    ~ProductoVenta();
};