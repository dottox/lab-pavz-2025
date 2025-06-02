#include "DtProducto.h"
DtProducto::DtProducto() {};

DtProducto::DtProducto(string codigo, string descripcion)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
}


string DtProducto::getDescripcion()
{
    return this->descripcion;
}
string DtProducto::getCodigo()
{
    return this->codigo;
}
DtProducto DtProducto::getProducto()
{
    return *this; // Retorna una copia del objeto actual
}

DtProducto::~DtProducto()
{

}