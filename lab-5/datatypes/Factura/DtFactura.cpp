#include "DtFactura.h"

DtFactura::DtFactura() {}

// Para crear una factura
DtFactura::DtFactura(int codigoVenta, DtFecha fecha, DtHora hora, IDictionary *productos, float subtotal, int descuento, float montoTotal, float ivaTotal)
{
    this->codigoVenta = codigoVenta;
    this->fecha = fecha;
    this->hora = hora;
    this->productosConsumidos = productos;
    this->subtotal = subtotal;
    this->descuento = descuento;
    this->montoTotal = montoTotal;
    this->ivaTotal = ivaTotal;
}

// Para mostrar una factura existente
DtFactura::DtFactura(int codigo, int codigoVenta, DtFecha fecha, DtHora hora, IDictionary *productos, float subtotal, int descuento, float montoTotal, float ivaTotal)
{
    this->codigo = codigo;
    this->codigoVenta = codigoVenta;
    this->fecha = fecha;
    this->hora = hora;
    this->productosConsumidos = productos;
    this->subtotal = subtotal;
    this->descuento = descuento;
    this->montoTotal = montoTotal;
    this->ivaTotal = ivaTotal;
}

DtFactura DtFactura::getFactura()
{
    return *this;
}

int DtFactura::getCodigo()
{
    return this->codigo;
}

int DtFactura::getCodigoVenta()
{
    return this->codigoVenta;
}

DtFecha DtFactura::getFecha()
{
    return this->fecha;
}

DtHora DtFactura::getHora()
{
    return this->hora;
}

IDictionary *DtFactura::getProductos()
{
    return this->productosConsumidos;
}

float DtFactura::getSubtotal()
{
    return this->subtotal;
}

int DtFactura::getDescuento()
{
    return this->descuento;
}

float DtFactura::getMontoTotal()
{
    return this->montoTotal;
}

float DtFactura::getIvaTotal()
{
    return this->ivaTotal;
}

DtFactura::~DtFactura() {}