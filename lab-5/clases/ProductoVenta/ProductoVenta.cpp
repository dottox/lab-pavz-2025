#include "ProductoVenta.h"

ProductoVenta::ProductoVenta(char *codigoProducto, TipoProducto tipoProducto, string descripcion, float precio, int cantidad)
{
    this->codigoProducto = codigoProducto;
    this->tipo = tipoProducto;
    this->descripcion = descripcion;
    this->precio = precio;
    this->cantidad = cantidad;
}

DtProducto *ProductoVenta::getProducto()
{
    DtProducto *producto = nullptr;
    if (this->tipo == TipoProducto::TipoPlato)
    {
        producto = new DtPlato(this->codigoProducto, this->descripcion, this->precio, this->cantidad);
    }
    else
    {
        producto = new DtMenu(this->codigoProducto, this->descripcion, this->precio, this->cantidad);
    }
    return producto;
}

char *ProductoVenta::getCodigoProducto()
{
    return this->codigoProducto;
}

TipoProducto ProductoVenta::getTipo()
{
    return this->tipo;
}

int ProductoVenta::getCantidad()
{
    return this->cantidad;
}

float ProductoVenta::getPrecio()
{
    return this->precio;
}

string ProductoVenta::getDescripcion()
{
    return this->descripcion;
}

void ProductoVenta::setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}

ostream &operator<<(ostream &os, const ProductoVenta &producto)
{
    os << "(x" << producto.cantidad << ") "
       << "Codigo Producto: " << producto.codigoProducto
       << ", Tipo: " << (producto.tipo == TipoProducto::TipoPlato ? "Plato" : "Menu")
       << ", Descripcion: " << producto.descripcion
       << ", Precio: $" << producto.precio;
    return os;
}

ProductoVenta::~ProductoVenta()
{
    this->codigoProducto = nullptr;
    delete[] this->codigoProducto; // Liberar memoria del codigo
}