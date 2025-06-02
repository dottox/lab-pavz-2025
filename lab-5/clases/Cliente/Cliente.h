#pragma once
#include <iostream>
#include "../../datatypes/Direccion/DtDireccion.h"
#include "../../datatypes/Cliente/DtCliente.h"

using namespace std;

class Cliente
{
private:
    string nombre;
    string telefono;
    DtDireccion direccion;

public:
    Cliente(DtCliente);
    string getNombre();
    string getTelefono();
    DtDireccion getDireccion();
    void setNombre(string);
    void setTelefono(string);
    void setDireccion(DtDireccion);
    ~Cliente();
};