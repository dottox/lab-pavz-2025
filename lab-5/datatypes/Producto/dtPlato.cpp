#include "dtPlato.h"

dtPlato::dtPlato(){}

dtPlato::dtPlato(string descripcion, string codigo, float precio) : dtProducto(codigo, descripcion)
{
    this->precio = precio;
}

float dtPlato::getPrecio()
{
    return this->precio;
}

dtPlato::~dtPlato() {}