#include "DtProducto.h"
DtProducto::DtProducto() {};

DtProducto::DtProducto(char* codigo, string descripcion, TipoProducto tipo)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->tipo = tipo;
    this->precio = 0.0f; // Inicializa el precio a 0.0 por defecto
}

DtProducto::DtProducto(char* codigo, string descripcion, TipoProducto tipo, float precio)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->tipo = tipo;
    this->precio = precio;
}

char* DtProducto::getCodigo() const
{
    return this->codigo;
}
string DtProducto::getDescripcion() const
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

float DtProducto::getPrecio() const
{
    return this->precio;
}

DtProducto::~DtProducto()
{

}