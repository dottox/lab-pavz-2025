#include "DtInfoProducto.h"

DtInfoProducto::DtInfoProducto() {}

DtInfoProducto::DtInfoProducto(DtProducto* producto, int cantidadVentas)
{
    this->producto = producto;
    this->cantidadVentas = cantidadVentas;
}

DtProducto* DtInfoProducto::getProducto()
{
    return this->producto;
}

int DtInfoProducto::getCantidadVentas()
{
    return this->cantidadVentas;
}

DtInfoProducto::~DtInfoProducto() {}