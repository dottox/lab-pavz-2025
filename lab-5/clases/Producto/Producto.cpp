#include "Producto.h"
#include "../../utils/utils.h"

Producto::Producto(dtProducto dtProducto)
{
    
    this->codigo = dtProducto.getCodigo();
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