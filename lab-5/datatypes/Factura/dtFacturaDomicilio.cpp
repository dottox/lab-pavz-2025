#include "DtFacturaDomicilio.h"

DtFacturaDomicilio::DtFacturaDomicilio() {}

DtFacturaDomicilio::DtFacturaDomicilio(int codigoVenta, DtFecha fecha, DtHora hora, DtConsumido **productos, float subtotal, int descuento, float montoTotal, float ivaTotal, string nombreRepartidor, Transporte transporte) 
: DtFactura(codigoVenta, fecha, hora, productos, subtotal, descuento, montoTotal, ivaTotal){
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