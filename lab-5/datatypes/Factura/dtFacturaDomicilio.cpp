#include "dtFacturaDomicilio.h"

dtFacturaDomicilio::dtFacturaDomicilio() {}

dtFacturaDomicilio::dtFacturaDomicilio(int codigoVenta, dtFecha fecha, dtHora hora, dtConsumido **productos, float subtotal, int descuento, float montoTotal, float ivaTotal, Venta* venta, string nombreRepartidor, Transporte transporte) 
: dtFactura(codigoVenta, fecha, hora, productos, subtotal, descuento, montoTotal, ivaTotal, venta){
    this->nombreRepartidor = nombreRepartidor;
    this->transporte = transporte;
}

string dtFacturaDomicilio::getNombreRepartidor()
{
    return this->nombreRepartidor;
}

Transporte dtFacturaDomicilio::getTransporte()
{
    return this->transporte;
}

dtFacturaDomicilio::~dtFacturaDomicilio() {};