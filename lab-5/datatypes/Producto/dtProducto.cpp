#include "dtProducto.h"
dtProducto::dtProducto() {};

dtProducto::dtProducto(string codigo, string descripcion)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
}


string dtProducto::getDescripcion()
{
    return this->descripcion;
}
string dtProducto::getCodigo()
{
    return this->codigo;
}
dtProducto dtProducto::getProducto()
{
    return *this; // Retorna una copia del objeto actual
}

dtProducto::~dtProducto()
{

}