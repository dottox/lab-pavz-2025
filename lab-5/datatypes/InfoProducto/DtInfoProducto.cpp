#include "DtInfoProducto.h"

DtInfoProducto::DtInfoProducto() {}

DtInfoProducto::DtInfoProducto(DtProducto* producto, int cantidadVentas)
{
    cout << "Creando DtInfoProducto con producto: " << producto->getCodigo() << " y cantidad de ventas: " << cantidadVentas << endl;
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