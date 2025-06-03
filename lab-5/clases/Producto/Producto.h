#pragma once

#include <iostream>
#include "../../datatypes/Producto/DtProducto.h"
#include "../../ICollection/interfaces/ICollectible.h"

#include "../../enums/TipoProducto.h"

using namespace std;

class Producto : public ICollectible
{
private:
    char* codigo;
    string descripcion;
    TipoProducto tipo;
    float precio;

protected:
    Producto(DtProducto);

public:
    char* getCodigo();
    string getDescripcion();
    TipoProducto getTipo();
    float getPrecio();
    friend ostream& operator<<(ostream&, const Producto&);
    virtual ~Producto();
};