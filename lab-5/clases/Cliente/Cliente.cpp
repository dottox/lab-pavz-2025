#include "Cliente.h"

Cliente::Cliente(dtCliente cliente)
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

dtDireccion Cliente::getDireccion()
{
    return this->direccion;
}

void Cliente::setTelefono(string telefono)
{
    this->telefono = telefono;
}

void Cliente::setDireccion(dtDireccion direccion)
{
    this->direccion = direccion;
}

Cliente::~Cliente()
{
    // Destructor implementation (if needed)
    // Currently, no dynamic memory allocation is done, so nothing specific to clean up.
}