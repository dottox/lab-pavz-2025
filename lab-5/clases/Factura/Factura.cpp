#include "Factura.h"

Factura::Factura(dtFactura factura){
    this->codigo = factura.getCodigo();
    this->fecha = factura.getFecha();
    this->hora = factura.getHora();
    this->productos = factura.getProductos();
    this->subtotal = factura.getSubtotal();
    this->descuento = factura.getDescuento();
    this->montoTotal = factura.getMontoTotal();
    this->ivaTotal = factura.getIvaTotal();
    this->venta = factura.getVenta();
}

int Factura::getCodigo(){
    return this->codigo;
}

dtFecha Factura::getFecha(){
    return this->fecha;
}

dtHora Factura::getHora(){
    return this->hora;
}

dtConsumido **Factura::getProductos(){
    return this->productos;
}

float Factura::getSubtotal(){
    return this->subtotal;
}

int Factura::getDescuento(){
    return this->descuento;
}

float Factura::getMontoTotal(){
    return this->montoTotal;
}

float Factura::getIvaTotal(){
    return this->ivaTotal;
}

Venta* Factura::getVenta(){
    return this->venta;
}

Factura::~Factura() {}