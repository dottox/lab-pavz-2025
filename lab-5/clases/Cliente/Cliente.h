#pragma once
#include <iostream>
#include "../../datatypes/Direccion/dtDireccion.h"
#include "../../datatypes/Cliente/dtCliente.h"

using namespace std;

class Cliente
{
private:
    string nombre;
    string telefono;
    dtDireccion direccion;

public:
    Cliente(dtCliente);
    string getNombre();
    string getTelefono();
    dtDireccion getDireccion();
    void setNombre(string);
    void setTelefono(string);
    void setDireccion(dtDireccion);
    ~Cliente();
};