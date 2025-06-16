#include "ProductoVenta.h"

ProductoVenta::ProductoVenta(char* codigoProducto, TipoProducto tipoProducto, string descripcion, float precio, int cantidad)
{
    this->codigoProducto = codigoProducto;
    this->tipo = tipoProducto;
    this->descripcion = descripcion;
    this->precio = precio;
    this->cantidad = cantidad;
}

DtProducto * ProductoVenta::getProducto()
{
    if(this->tipo == TipoProducto::TipoPlato)
    {
        return new DtPlato(this->codigoProducto, this->descripcion, this->precio);
    }else{
        return new DtMenu(this->codigoProducto, this->descripcion, this->precio);   
    }
}

char* ProductoVenta::getCodigoProducto()
{
    return this->codigoProducto;
}

TipoProducto ProductoVenta::getTipo()
{
    return this->tipo;
}

int ProductoVenta::getCantidad()
{
    return this->cantidad;
}

float ProductoVenta::getPrecio()
{
    return this->precio;
}

string ProductoVenta::getDescripcion()
{
    return this->descripcion;
}

void ProductoVenta::setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}

ProductoVenta::~ProductoVenta()
{
    this->codigoProducto = nullptr; 
}