#pragma once

#include <iostream>

#include "../Producto/Producto.h"
#include "../Venta/Venta.h"
#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;

class ProductoVenta : public ICollectible
{
private:
    char* codigoProducto;
    TipoProducto tipo;
    string descripcion;
    float precio;
    int cantidad;

public:
    ProductoVenta(char*, TipoProducto, string, float, int);
    DtProducto * getProducto();
    char* getCodigoProducto();
    TipoProducto getTipo();
    string getDescripcion();
    float getPrecio();
    int getCantidad();
    void setCantidad(int);
    ~ProductoVenta();
};