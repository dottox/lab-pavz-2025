#include "DtFactura.h"


DtFactura::DtFactura() {}

DtFactura::DtFactura(int codigoVenta, DtFecha fecha, DtHora hora, DtConsumido **productos, float subtotal, int descuento, float montoTotal, float ivaTotal){
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

DtFactura::DtFactura(int codigo, int codigoVenta, DtFecha fecha, DtHora hora, DtConsumido **productos, float subtotal, int descuento, float montoTotal, float ivaTotal){
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

DtFactura DtFactura::getFactura(){
    return *this;
}

int DtFactura::getCodigo(){
    return this->codigo;
}

int DtFactura::getCodigoVenta(){
    return this->codigoVenta;
}

DtFecha DtFactura::getFecha(){
    return this->fecha;
}

DtHora DtFactura::getHora(){
    return this->hora;
}

DtConsumido **DtFactura::getProductos(){
    return this->productos;
}

float DtFactura::getSubtotal(){
    return this->subtotal;
}

int DtFactura::getDescuento(){
    return this->descuento;
}

float DtFactura::getMontoTotal(){
    return this->montoTotal;
}

float DtFactura::getIvaTotal(){
    return this->ivaTotal;
}

DtFactura::~DtFactura() {}