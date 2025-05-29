#include "dtConsumido.h"

dtConsumido::dtConsumido() {}

dtConsumido::dtConsumido(string descripcion, int cantidad, float precio)
{
    this->descripcion = descripcion;
    this->cantidad = cantidad;
    this->precio = precio;
}

string dtConsumido::getDescripcion()
{
    return this->descripcion;
}

int dtConsumido::getCantidad()
{
    return this->cantidad;
}

float dtConsumido::getPrecio()
{
    return this->precio;
}

dtConsumido::~dtConsumido() {}