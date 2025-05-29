#include "VentaLocal.h"

VentaLocal::VentaLocal(int codigo, float subtotal, int descuento, Producto **productos, int cantidadProductos)
    : Venta(codigo, subtotal, descuento, productos, cantidadProductos)
{
    // Constructor body can be empty as the base class constructor initializes everything
}

VentaLocal::~VentaLocal()
{
    // No additional cleanup needed, as the base class destructor will handle the deletion of productos
    // If there were any additional resources to clean up, they would be handled here
}