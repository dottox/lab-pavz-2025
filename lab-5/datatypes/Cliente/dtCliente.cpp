#include "dtCliente.h"

dtCliente::dtCliente(string nombre, string telefono, dtDireccion direccion)
{
    this->nombre = nombre;
    this->telefono = telefono;
    this->direccion = direccion;
}

string dtCliente::getNombre()
{
    return this->nombre;
}

string dtCliente::getTelefono()
{
    return this->telefono;
}

dtDireccion dtCliente::getDireccion()
{
    return this->direccion;
}

dtCliente::~dtCliente()
{
    // Destructor vacio
    // No es necesario liberar memoria ya que no se utilizan punteros
}