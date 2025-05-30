#include "VentaDomicilio.h"

VentaDomicilio::VentaDomicilio(int codigo, float subtotal, int descuento, Producto **productos, int cantidadProductos, dtCliente datosCliente)
    : Venta(codigo, subtotal, descuento, productos, cantidadProductos), datosCliente(datosCliente)
{
    this->datosCliente = datosCliente;
}

VentaDomicilio::~VentaDomicilio()
{
    // No additional cleanup needed, as the base class destructor will handle the deletion of productos
    // If there were any additional resources to clean up, they would be handled here
}