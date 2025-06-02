#include "DtCliente.h"

DtCliente::DtCliente(string nombre, string telefono, dtDireccion direccion)
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

dtDireccion DtCliente::getDireccion()
{
    return this->direccion;
}

DtCliente::~DtCliente()
{
    // Destructor vacio
    // No es necesario liberar memoria ya que no se utilizan punteros
}