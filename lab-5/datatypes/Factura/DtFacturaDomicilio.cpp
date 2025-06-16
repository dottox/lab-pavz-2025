#include "DtFacturaDomicilio.h"

DtFacturaDomicilio::DtFacturaDomicilio() {}

DtFacturaDomicilio::DtFacturaDomicilio(DtFactura factura, string nombreRepartidor, Transporte transporte)
    : DtFactura(
          factura.getCodigo(),
          factura.getCodigoVenta(),
          factura.getFecha(),
          factura.getHora(),
          factura.getProductos(),
          factura.getSubtotal(),
          factura.getDescuento(),
          factura.getMontoTotal(),
          factura.getIvaTotal())
{
    this->nombreRepartidor = nombreRepartidor;
    this->transporte = transporte;
}

string DtFacturaDomicilio::getNombreRepartidor()
{
    return this->nombreRepartidor;
}

Transporte DtFacturaDomicilio::getTransporte()
{
    return this->transporte;
}

DtFacturaDomicilio::~DtFacturaDomicilio() {};