#pragma once

#include <iostream>
#include "../../datatypes/Producto/dtProducto.h"

using namespace std;

class Producto
{
private:
    string codigo;
    string descripcion;
    float precio;

public:
    Producto(dtProducto);
    string getCodigo();
    string getDescripcion();
    float getPrecio();
    void setPrecio(float);
    virtual ~Producto();
};