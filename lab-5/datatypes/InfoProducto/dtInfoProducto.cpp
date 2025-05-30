#include "dtInfoProducto.h"

dtInfoProducto::dtInfoProducto() {}

dtInfoProducto::dtInfoProducto(dtProducto producto, int cantidadVentas)
{
    this->producto = producto;
    this->cantidadVentas = cantidadVentas;
}

dtProducto dtInfoProducto::getProducto()
{
    return this->producto;
}

int dtInfoProducto::getCantidadVentas()
{
    return this->cantidadVentas;
}

dtInfoProducto::~dtInfoProducto() {}