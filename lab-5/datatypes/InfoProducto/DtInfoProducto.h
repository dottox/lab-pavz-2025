#pragma once

#include <iostream>
#include "../Producto/DtProducto.h"

using namespace std;

class DtInfoProducto
{
private:
    DtProducto* producto;
    int cantidadVentas;

public:
    DtInfoProducto();
    DtInfoProducto(DtProducto*, int);
    DtProducto* getProducto();
    int getCantidadVentas();
    ~DtInfoProducto();
};
