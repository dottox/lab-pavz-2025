#include "dtFactura.h"


dtFactura::dtFactura() {}

dtFactura::dtFactura(int codigoVenta, dtFecha fecha, dtHora hora, dtConsumido **productos, float subtotal, int descuento, float montoTotal, float ivaTotal){
    this->codigo = -1; // Default value for codigo
    this->codigoVenta = codigoVenta;
    this->fecha = fecha;
    this->hora = hora;
    this->productos = productos;
    this->subtotal = subtotal;
    this->descuento = descuento;
    this->montoTotal = montoTotal;
    this->ivaTotal = ivaTotal;
}

dtFactura::dtFactura(int codigo, int codigoVenta, dtFecha fecha, dtHora hora, dtConsumido **productos, float subtotal, int descuento, float montoTotal, float ivaTotal){
    this->codigo = codigo;
    this->codigoVenta = codigoVenta;
    this->fecha = fecha;
    this->hora = hora;
    this->productos = productos;
    this->subtotal = subtotal;
    this->descuento = descuento;
    this->montoTotal = montoTotal;
    this->ivaTotal = ivaTotal;
}

dtFactura dtFactura::getFactura(){
    return *this;
}

int dtFactura::getCodigo(){
    return this->codigo;
}

int dtFactura::getCodigoVenta(){
    return this->codigoVenta;
}

dtFecha dtFactura::getFecha(){
    return this->fecha;
}

dtHora dtFactura::getHora(){
    return this->hora;
}

dtConsumido **dtFactura::getProductos(){
    return this->productos;
}

float dtFactura::getSubtotal(){
    return this->subtotal;
}

int dtFactura::getDescuento(){
    return this->descuento;
}

float dtFactura::getMontoTotal(){
    return this->montoTotal;
}

float dtFactura::getIvaTotal(){
    return this->ivaTotal;
}

dtFactura::~dtFactura() {}