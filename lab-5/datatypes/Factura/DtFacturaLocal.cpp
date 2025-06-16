#include "DtFacturaLocal.h"

DtFacturaLocal::DtFacturaLocal() {}

DtFacturaLocal::DtFacturaLocal(DtFactura factura, string nombreMozo)
    : DtFactura(
          factura.getCodigoVenta(),
          factura.getFecha(),
          factura.getHora(),
          factura.getProductos(),
          factura.getSubtotal(),
          factura.getDescuento(),
          factura.getMontoTotal(),
          factura.getIvaTotal())
{
    this->nombreMozo = nombreMozo;
}

string DtFacturaLocal::getNombreMozo()
{
    return this->nombreMozo;
};

DtFacturaLocal::~DtFacturaLocal() {};