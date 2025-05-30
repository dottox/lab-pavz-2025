#pragma once

#include <iostream>
#include "../../datatypes/Producto/dtProducto.h"

using namespace std;

class Producto
{
private:
    string codigo;
    string descripcion;

public:
    Producto(dtProducto);
    string getCodigo();
    string getDescripcion();
    virtual ~Producto();
};