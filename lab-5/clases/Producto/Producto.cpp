#include "Producto.h"

Producto::Producto(dtProducto dtProducto)
{
    
    this->codigo = dtProducto.getId();
    this->descripcion = dtProducto.getDescripcion();
    this->precio = dtProducto.getPrecio();
}

string Producto::getCodigo()
{
    return this->codigo;
}

string Producto::getDescripcion()
{
    return this->descripcion;
}

float Producto::getPrecio()
{
    return this->precio;
}

void Producto::setPrecio(float precio)
{
    this->precio = precio;
}

Producto::~Producto() {}