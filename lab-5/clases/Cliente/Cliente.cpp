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
       << "Telefono: " << Cliente.telefono << endl
       << "Direccion: " << Cliente.direccion << endl;
    return os;
}

Cliente::~Cliente()
{
    // Destructor implementation (if needed)
    // Currently, no dynamic memory allocation is done, so nothing specific to clean up.
}