#include "DtCliente.h"

DtCliente::DtCliente()
{
}

DtCliente::DtCliente(string nombre, string telefono, DtDireccion direccion)
{
    this->nombre = nombre;
    this->telefono = telefono;
    this->direccion = direccion;
}

string DtCliente::getNombre()
{
    return this->nombre;
}

string DtCliente::getTelefono()
{
    return this->telefono;
}

DtDireccion DtCliente::getDireccion()
{
    return this->direccion;
}

ostream& operator<<(ostream& os, const DtCliente& dtCliente)
{
    os << "Nombre: " << dtCliente.nombre << ", Telefono: " << dtCliente.telefono
       << ", Direccion: " << dtCliente.direccion;
    return os;
}


DtCliente::~DtCliente()
{
    // Destructor vacio
    // No es necesario liberar memoria ya que no se utilizan punteros
}