#include "DtProducto.h"
DtProducto::DtProducto() {};

DtProducto::DtProducto(char* codigo, string descripcion, TipoProducto tipo, float precio)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->tipo = tipo;
    this->precio = precio;
}

char* DtProducto::getCodigo()
{
    return this->codigo;
}
string DtProducto::getDescripcion()
{
    return this->descripcion;
}

DtProducto DtProducto::getProducto()
{
    return *this; // Retorna una copia del objeto actual
}

TipoProducto DtProducto::getTipo()
{
    return this->tipo;
}

float DtProducto::getPrecio()
{
    return this->precio;
}

DtProducto::~DtProducto()
{

}