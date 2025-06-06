#include "FacturaLocal.h"

FacturaLocal::FacturaLocal(DtFacturaLocal factura) : Factura(factura.getFactura())
{
    this->nombreMozo = factura.getNombreMozo();
};

string FacturaLocal::getNombreMozo()
{
    return this->nombreMozo;
};

DtFacturaLocal FacturaLocal::getDatos()
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

    return DtFacturaLocal(factura, this->nombreMozo);
}

FacturaLocal::~FacturaLocal() {};