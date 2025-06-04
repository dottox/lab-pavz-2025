#pragma once

#include <iostream>
#include <cstring> // Para usar strlen y strcpy (cosas del char* -.-)
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
    Producto(const DtProducto *);

public:
    char* getCodigo() const;
    string getDescripcion() const;
    TipoProducto getTipo() const;
    float getPrecio() const;
    void setPrecio(float);
    friend ostream& operator<<(ostream&, const Producto&);
    virtual ~Producto();
};