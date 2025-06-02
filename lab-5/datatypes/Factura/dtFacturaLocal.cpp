#include "DtFacturaLocal.h"

DtFacturaLocal::DtFacturaLocal() {}

DtFacturaLocal::DtFacturaLocal(int codigoVenta, DtFecha fecha, DtHora hora, DtConsumido **productos, float subtotal, int descuento, float montoTotal, float ivaTotal, string nombreMozo)
    : DtFactura(codigoVenta, fecha, hora, productos, subtotal, descuento, montoTotal, ivaTotal){
    this->nombreMozo = nombreMozo;
}

string DtFacturaLocal::getNombreMozo()
{
    return this->nombreMozo;
};

DtFacturaLocal::~DtFacturaLocal() {};