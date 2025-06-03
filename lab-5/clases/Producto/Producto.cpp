#include "Producto.h"
#include "../../utils/utils.h"

Producto::Producto(DtProducto dtProducto)
{
    
    this->codigo = dtProducto.getCodigo();
    this->descripcion = dtProducto.getDescripcion();
    this->tipo = dtProducto.getTipo();
    this->precio = dtProducto.getPrecio();
}

char* Producto::getCodigo()
{
    return this->codigo;
}

string Producto::getDescripcion()
{
    return this->descripcion;
}

TipoProducto Producto::getTipo()
{
    return this->tipo;
}

float Producto::getPrecio()
{
    return this->precio;
}

ostream& operator<<(ostream& os, const Producto& producto)
{
    os << "Codigo: " << producto.codigo << ", Descripcion: " << producto.descripcion
       << ", Tipo: " << (producto.tipo == TipoPlato ? "Plato" : "Menu")
       << ", Precio: $" << producto.precio;
    return os;
}

Producto::~Producto() {
}