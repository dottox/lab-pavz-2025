#pragma once

#include <iostream>

#include "../Producto/Producto.h"
#include "../Venta/Venta.h"
#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;

class ProductoVenta : public ICollectible
{
private:
    string descripcion;
    int cantidad;
    float precio;
    Producto *producto;

public:
    ProductoVenta(string, int, float, Producto *);
    Producto *getProducto();
    int getCantidad();
    float getPrecio();
    string getDescripcion();
    void setCantidad(int);
    ~ProductoVenta();
};