#include "FacturaDomicilio.h"

FacturaDomicilio::FacturaDomicilio(dtFacturaDomicilio factura) : Factura(factura.getFactura())
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