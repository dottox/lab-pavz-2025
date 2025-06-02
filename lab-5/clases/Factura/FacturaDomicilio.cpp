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

FacturaDomicilio::~FacturaDomicilio() {};