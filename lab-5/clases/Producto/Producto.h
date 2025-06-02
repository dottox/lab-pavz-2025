#pragma once

#include <iostream>
#include "../../datatypes/Producto/dtProducto.h"
#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;

class Producto : ICollectible
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