#include "Producto.h"

Producto::Producto(dtProducto dtProducto)
{
    
    this->codigo = dtProducto.getId();
    this->descripcion = dtProducto.getDescripcion();

}

string Producto::getCodigo()
{
    return this->codigo;
}

string Producto::getDescripcion()
{
    return this->descripcion;
}


Producto::~Producto() {}