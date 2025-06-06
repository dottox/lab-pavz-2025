#include "Factura.h"
#include "../../utils/utils.h"

Factura::Factura(DtFactura factura)
{
    this->codigo = utils::generarNumeroFactura();
    this->codigoVenta = factura.getCodigoVenta();
    this->fecha = factura.getFecha();
    this->hora = factura.getHora();
    this->productosConsumidos = factura.getProductos();
    this->subtotal = factura.getSubtotal();
    this->descuento = factura.getDescuento();
    this->montoTotal = factura.getMontoTotal();
    this->ivaTotal = factura.getIvaTotal();
}

int Factura::getCodigo()
{
    return this->codigo;
}

DtFecha Factura::getFecha()
{
    return this->fecha;
}

DtHora Factura::getHora()
{
    return this->hora;
}

float Factura::getSubtotal()
{
    return this->subtotal;
}

int Factura::getDescuento()
{
    return this->descuento;
}

float Factura::getMontoTotal()
{
    return this->montoTotal;
}

float Factura::getIvaTotal()
{
    return this->ivaTotal;
}

int Factura::getCodigoVenta()
{
    return this->codigoVenta;
}

IDictionary *Factura::getProductos()
{
    return this->productosConsumidos;
}

Factura::~Factura() {}