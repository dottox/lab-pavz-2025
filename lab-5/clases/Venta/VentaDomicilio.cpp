#include "VentaDomicilio.h"

VentaDomicilio::VentaDomicilio(DtCliente* datosCliente) : Venta(), datosCliente(datosCliente)
{
    // Constructor body can be empty as the base class constructor initializes everything
}

DtCliente* VentaDomicilio::getDatosCliente() const
{
    return this->datosCliente;
}

ostream & operator<<(ostream &os, const VentaDomicilio &ventaDomicilio) {
    os << "Venta domicilio: " << static_cast<const Venta&>(ventaDomicilio) << endl
       << "    " << *(ventaDomicilio.datosCliente);
    return os;
}

VentaDomicilio::~VentaDomicilio()
{
    delete this->datosCliente; 
}