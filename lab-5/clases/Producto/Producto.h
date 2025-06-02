#pragma once

#include <iostream>
#include "../../datatypes/Producto/DtProducto.h"
#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;

class Producto : ICollectible
{
private:
    string codigo;
    string descripcion;

public:
    Producto(DtProducto);
    string getCodigo();
    string getDescripcion();
    virtual ~Producto();
};