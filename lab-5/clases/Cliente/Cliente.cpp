#include "Cliente.h"

Cliente::Cliente(DtCliente cliente)
{
    this->nombre = cliente.getNombre();
    this->telefono = cliente.getTelefono();
    this->direccion = cliente.getDireccion();
};

string Cliente::getNombre()
{
    return this->nombre;
}

string Cliente::getTelefono()
{
    return this->telefono;
}

DtCliente *Cliente::getDatos()
{
    return new DtCliente(this->nombre, this->telefono, this->direccion);
}

DtDireccion Cliente::getDireccion()
{
    return this->direccion;
}

void Cliente::setTelefono(string telefono)
{
    this->telefono = telefono;
}

void Cliente::setDireccion(DtDireccion direccion)
{
    this->direccion = direccion;
}

void Cliente::setNombre(string nombre)
{
    this->nombre = nombre;
}
ostream &operator<<(ostream &os, const Cliente &Cliente)
{
    os << "Cliente: " << Cliente.nombre << endl
       << "Telefono: " << Cliente.telefono << endl;
    // Try to print as DtDireccionApto
    try {
        const DtDireccionApto& direccionApto = dynamic_cast<const DtDireccionApto&>(Cliente.direccion);
        os << "Direccion: " << direccionApto << endl;
    } catch (const std::bad_cast&) {
        try {
            const DtDireccionCasa& direccionCasa = dynamic_cast<const DtDireccionCasa&>(Cliente.direccion);
            os << "Direccion: " << direccionCasa << endl;
        } catch (const std::bad_cast&) {
            // Fallback to base class
            os << "Direccion: " << Cliente.direccion << endl;
        }
    }
    return os;
}

Cliente::~Cliente()
{
    // Destructor implementation (if needed)
    // Currently, no dynamic memory allocation is done, so nothing specific to clean up.
}