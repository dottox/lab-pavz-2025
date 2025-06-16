#include "VentaDomicilio.h"

VentaDomicilio::VentaDomicilio(DtCliente *datosCliente, int cantidadProductos, float subtotal, IDictionary *productosConsumidos) : Venta(cantidadProductos, subtotal, productosConsumidos)
{
    this->datosCliente = new DtCliente(*datosCliente);
}

DtCliente *VentaDomicilio::getDatosCliente() const
{
    return this->datosCliente;
}

ostream &operator<<(ostream &os, const VentaDomicilio &ventaDomicilio)
{
    os << "Venta domicilio: " << static_cast<const Venta &>(ventaDomicilio) << endl
       << "    " << *(ventaDomicilio.datosCliente);
    return os;
}

VentaDomicilio::~VentaDomicilio()
{
    delete this->datosCliente;
}