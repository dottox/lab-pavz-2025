#include "dtFacturaLocal.h"

dtFacturaLocal::dtFacturaLocal() {}

dtFacturaLocal::dtFacturaLocal(int codigoVenta, dtFecha fecha, dtHora hora, dtConsumido **productos, float subtotal, int descuento, float montoTotal, float ivaTotal, string nombreMozo)
    : dtFactura(codigoVenta, fecha, hora, productos, subtotal, descuento, montoTotal, ivaTotal){
    this->nombreMozo = nombreMozo;
}

string dtFacturaLocal::getNombreMozo()
{
    return this->nombreMozo;
};

dtFacturaLocal::~dtFacturaLocal() {};