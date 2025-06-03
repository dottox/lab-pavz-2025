#pragma once

#include <iostream>

#include "../../enums/TipoProducto.h"

#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;

class DtProducto : public ICollectible
{
private:
    char* codigo;
    string descripcion;
    TipoProducto tipo;
    float precio;

public:
    DtProducto();
    DtProducto(char*, string, TipoProducto, float);
    char* getCodigo();
    string getDescripcion();
    DtProducto getProducto();
    TipoProducto getTipo();
    float getPrecio();
    virtual ~DtProducto();
};
