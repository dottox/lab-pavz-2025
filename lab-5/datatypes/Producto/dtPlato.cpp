#include "dtPlato.h"

dtPlato::dtPlato(int id, string descripcion, string codigo, float precio) : dtProducto(id, descripcion, codigo)
{
    this->precio = precio;
}

float dtPlato::getPrecio()
{
    return this->precio;
}

dtPlato::~dtPlato() {}