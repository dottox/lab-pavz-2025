#include "DtConsumido.h"

DtConsumido::DtConsumido() {}

DtConsumido::DtConsumido(char* codigo, string descripcion, int cantidad, float precio)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->cantidad = cantidad;
    this->precio = precio;
}

char* DtConsumido::getCodigo()
{
    return this->codigo;
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

ostream &operator<<(ostream &os, const DtConsumido &dtConsumido)
{
    os << "Descripcion: " << dtConsumido.descripcion
       << ", Cantidad: " << dtConsumido.cantidad
       << ", Precio: " << dtConsumido.precio;
    return os;
}

DtConsumido::~DtConsumido() {}