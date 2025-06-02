#include "DtPlato.h"

DtPlato::DtPlato(){}

DtPlato::DtPlato(string descripcion, string codigo, float precio) : DtProducto(codigo, descripcion)
{
    this->precio = precio;
}

float DtPlato::getPrecio()
{
    return this->precio;
}

DtPlato::~DtPlato() {}