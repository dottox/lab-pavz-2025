#pragma once

#include <iostream>
#include "Producto.h"
#include "../../datatypes/Producto/dtProducto.h"
#include "../../datatypes/Producto/dtPlato.h"
using namespace std;

class Plato : public Producto
{
public:
    Plato(dtPlato);
    ~Plato();
};