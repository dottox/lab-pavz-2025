#include "VentaLocal.h"

VentaLocal::VentaLocal() : Venta()
{
    // Constructor body can be empty as the base class constructor initializes everything
}

ostream & operator<<(ostream &os, const VentaLocal &ventaLocal) {
    os << "Venta local: " << static_cast<const Venta>(ventaLocal); // Call base class operator<<
    return os;
}

VentaLocal::~VentaLocal()
{
    // No additional cleanup needed, as the base class destructor will handle the deletion of productos
    // If there were any additional resources to clean up, they would be handled here
}