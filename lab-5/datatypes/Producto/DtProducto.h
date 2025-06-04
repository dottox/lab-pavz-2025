#pragma once

#include <iostream>
#include <cstring> // Para strlen y strcpy

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
    DtProducto(const char* codigo, string descripcion, TipoProducto tipo);
    DtProducto(const char* codigo, string descripcion, TipoProducto tipo, float precio);
    DtProducto(const DtProducto&); 
    DtProducto& operator=(const DtProducto&); 

    virtual ~DtProducto();

    char* getCodigo() const;
    string getDescripcion() const;
    TipoProducto getTipo() const;
    float getPrecio() const;

    // Método que retorna una copia profunda del objeto
    virtual DtProducto* clone() const = 0;
};
