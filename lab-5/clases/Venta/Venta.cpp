#include "Venta.h"

Venta::Venta(int codigo, float subtotal, int descuento, Producto **productos, int cantidadProductos)
{
    this->codigo = codigo;
    this->subtotal = subtotal;
    this->descuento = descuento;
    this->productos = productos;
    this->cantidadProductos = cantidadProductos;
    this->factura = NULL;
}

int Venta::getCodigo()
{
    return this->codigo;
}

float Venta::getSubtotal()
{
    return this->subtotal;
}

int Venta::getDescuento()
{
    return this->descuento;
}

Producto **Venta::getProductos()
{
    return this->productos;
}

int Venta::getCantidadProductos()
{
    return this->cantidadProductos;
}

bool Venta::estaFacturada()
{
    return this->factura != NULL;
}

void Venta::setSubtotal(float subtotal)
{
    this->subtotal = subtotal;
}

void Venta::setDescuento(int descuento)
{
    this->descuento = descuento;
}

void Venta::setProductos(Producto **productos, int cantidadProductos)
{
    this->productos = productos;
    this->cantidadProductos = cantidadProductos;
}

Venta::~Venta()
{
    // Assuming productos is dynamically allocated, we need to delete it
    for (int i = 0; i < cantidadProductos; ++i)
    {
        delete productos[i]; // Delete each Producto object
    }
    delete[] productos; // Delete the array of Producto pointers
}