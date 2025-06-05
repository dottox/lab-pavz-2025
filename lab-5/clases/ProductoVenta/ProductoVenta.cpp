#include "ProductoVenta.h"

ProductoVenta::ProductoVenta(string descripcion, int cantidad, float precio, Producto *producto)
{
    this->descripcion = descripcion;
    this->cantidad = cantidad;
    this->precio = precio;
    this->producto = producto;
}

Producto *ProductoVenta::getProducto()
{
    return this->producto;
}

int ProductoVenta::getCantidad()
{
    return this->cantidad;
}

float ProductoVenta::getPrecio()
{
    return this->producto->getPrecio();
}

string ProductoVenta::getDescripcion()
{
    return this->producto->getDescripcion();
}

void ProductoVenta::setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}

ProductoVenta::~ProductoVenta()
{
    // Destructor logic if needed, currently does nothing
    // Note: The Venta and Producto pointers are not deleted here
    // because they are managed by their respective classes.
    // If they are dynamically allocated, their ownership should be handled elsewhere.
    // This prevents double deletion and memory leaks.
}