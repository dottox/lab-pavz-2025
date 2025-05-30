#pragma once

#include <iostream>
#include "../Producto/dtProducto.h"

using namespace std;

class dtInfoProducto
{
private:
    dtProducto producto;
    int cantidadVentas;

public:
    dtInfoProducto();
    dtInfoProducto(dtProducto, int);
    dtProducto getProducto();
    int getCantidadVentas();
    ~dtInfoProducto();
};
