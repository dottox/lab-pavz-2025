#pragma once

#include <iostream>
#include "Producto.h"
#include "../../datatypes/Producto/DtProducto.h"
#include "../../datatypes/Producto/DtPlato.h"
using namespace std;

class Plato : public Producto
{
public:
    Plato(DtPlato);
    ~Plato();
};