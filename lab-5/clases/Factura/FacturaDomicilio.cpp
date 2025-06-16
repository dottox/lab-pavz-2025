#include "FacturaDomicilio.h"

FacturaDomicilio::FacturaDomicilio(DtFacturaDomicilio factura) : Factura(factura.getFactura())
{
    this->nombreRepartidor = factura.getNombreRepartidor();
    this->transporte = factura.getTransporte();
}

string FacturaDomicilio::getNombreRepartidor()
{
    return this->nombreRepartidor;
}

Transporte FacturaDomicilio::getTransporte()
{
    return this->transporte;
}

DtFacturaDomicilio FacturaDomicilio::getDatos()
{
    DtFactura factura = DtFactura(
        this->getCodigo(),
        this->getCodigoVenta(),
        this->getFecha(),
        this->getHora(),
        this->getProductos(),
        this->getSubtotal(),
        this->getDescuento(),
        this->getMontoTotal(),
        this->getIvaTotal());

    return DtFacturaDomicilio(factura, this->nombreRepartidor, this->transporte);
}

FacturaDomicilio::~FacturaDomicilio() {};