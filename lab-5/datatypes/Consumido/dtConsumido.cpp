#include "DtConsumido.h"

DtConsumido::DtConsumido() {}

DtConsumido::DtConsumido(string descripcion, int cantidad, float precio)
{
    this->descripcion = descripcion;
    this->cantidad = cantidad;
    this->precio = precio;
}

string DtConsumido::getDescripcion()
{
    return this->descripcion;
}

int DtConsumido::getCantidad()
{
    return this->cantidad;
}

float DtConsumido::getPrecio()
{
    return this->precio;
}

DtConsumido::~DtConsumido() {}