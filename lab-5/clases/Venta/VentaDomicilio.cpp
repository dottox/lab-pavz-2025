#include "VentaDomicilio.h"

VentaDomicilio::VentaDomicilio(DtCliente datosCliente) : Venta()
{
    this->datosCliente = datosCliente;
}

DtCliente VentaDomicilio::getDatosCliente()
{
    return this->datosCliente;
}

ostream & operator<<(ostream &os, const VentaDomicilio &ventaDomicilio) {
    os << "Venta domicilio: " << static_cast<const Venta>(ventaDomicilio) << endl
       << "    " << ventaDomicilio.datosCliente;
    return os;
}

VentaDomicilio::~VentaDomicilio()
{
    // No additional cleanup needed, as the base class destructor will handle the deletion of productos
    // If there were any additional resources to clean up, they would be handled here
}