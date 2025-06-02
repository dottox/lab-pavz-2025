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

Cliente::~Cliente()
{
    // Destructor implementation (if needed)
    // Currently, no dynamic memory allocation is done, so nothing specific to clean up.
}